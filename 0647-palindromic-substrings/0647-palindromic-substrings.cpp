class Solution {
public:
    



    int outwardFromCenter(string &s, int i, int j){
        int result=0;
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            result+=1;
            i--;
            j++;
        }
        return result;
    }

    int countSubstrings (string s) {
        if(s.size()==1) return 1; 
        int result=0;
        for(int i=0;i<s.size();i++){ 
            result += outwardFromCenter(s,i,i);
            result += outwardFromCenter(s,i,i+1);
        }
        return result;
    }
};