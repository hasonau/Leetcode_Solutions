class Solution {
public:
    int t[101];
    
    int recursive(string& s,int i,int n){
        if(i >= n) return 1;
        if(s[i]== '0') return 0;
        if(t[i]!=-1) return t[i];
        // if(s.substr(i,length) - 'Z')> 26 return 0; i know the syntax is wrong, iam just writing it for this momemt to make u understan what ii am trying to do
       
        int left = recursive(s,i+1,n);
        int right=0;
        if(i + 1 < n){
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num <= 26) right = recursive(s, i + 2, n);
        }

        return t[i] = left+right;
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
        if(s.size()==1 && s[0]=='0') return 0;
        else if(s.size()==1) return 1;


        int n= s.size();
        return recursive(s,0,n);
    }
};