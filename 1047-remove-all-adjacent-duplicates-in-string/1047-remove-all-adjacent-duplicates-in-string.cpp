class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>s1;
        s1.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!s1.empty()){
                if(s[i]==s1.top()) s1.pop();
                else s1.push(s[i]);
            }
            else s1.push(s[i]);
        }
        s="";
        while(!s1.empty()){
            s+=s1.top();
            s1.pop();
        } 
        reverse(s.begin(),s.end());
        return s;
    }
};