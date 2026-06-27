class Solution {
public:
    pair<int,int> helper(string &s, int i, int j){
    int start = i, end = j-1;
    while(i >= 0 && j < s.size() && s[i] == s[j]){
        start = i;
        end = j;
        i--;
        j++;
    }
    return make_pair(start, end - start + 1);
}
    string longestPalindrome(string s) {
        // edge case
        if(s.size()==1) return s;
        string maximum="";
        for(int i=0;i<s.size();i++){
                pair<int,int> result = helper(s,i,i+1);
                string current = s.substr(result.first, result.second);
                if (current.length() > maximum.length()) {
                    maximum = current;
                }       
        }
        for(int i=0;i<s.size();i++){
                pair<int,int> result = helper(s,i,i);
                string current = s.substr(result.first, result.second);
                if (current.length() > maximum.length()) {
                    maximum = current;
                }       
        }
    return maximum;
    }
};