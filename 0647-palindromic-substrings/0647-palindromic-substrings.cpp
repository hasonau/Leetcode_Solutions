class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
        while(i<=j && s[i]==s[j]){
            i++;
            j--;
        }
        return i>j;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            count++;
            for(int j=i+1;j<s.size();j++){
                if(isPalindrome(s,i,j)) count++;
            }
        }
        return count;
    }
};