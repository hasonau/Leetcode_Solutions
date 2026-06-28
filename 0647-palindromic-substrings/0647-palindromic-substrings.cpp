class Solution {
public:
    
    bool dp[1001][1001]={};

    bool isPalindrome(string &s){
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void rightMovement(string &s,int index){
        string currentString(1, s[index]);
        int startingIndex=index;
        while(index<= s.size()-1 && isPalindrome(currentString)){
            int j = startingIndex + (int)currentString.size() - 1;
            if(!dp[startingIndex][j]) dp[startingIndex][j]=true;
            index++;
            if(index<=0) currentString += s[index];
        }
    }

    void outwardFromCenter(string &s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            if(!dp[i][j]) dp[i][j]=true;
            i--;
            j++;
        }
    }

    int countSubstrings (string s) {
        if(s.size()==1) return 1; 
        for(int i=0;i<s.size();i++){
            rightMovement(s,i);   
            outwardFromCenter(s,i,i);
            outwardFromCenter(s,i,i+1);
        }
        int count=0;
        for(int i=0;i<s.size();i++)
            for(int j=i;j<s.size();j++)
                if(dp[i][j]) count++;
        return count;
    }
};