class Solution {
public:

    int outFromCenter(string& s, int i ,int j){
        int count=0;
        while(i>=0 && j<=s.size()-1 && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
                count+=(outFromCenter(s,i,i)+outFromCenter(s,i,i+1));
        }
        return count;
    }
};