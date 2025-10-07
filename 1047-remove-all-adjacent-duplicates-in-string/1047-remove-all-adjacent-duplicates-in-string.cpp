class Solution {
public:
    string removeDuplicates(string s) {
        
        for(int i=1;i<s.size();i++){
            if (s[i]==s[i-1]){
                s.erase(i-1,2);
                i=0;
            } 
        }
        return s;
    }
};