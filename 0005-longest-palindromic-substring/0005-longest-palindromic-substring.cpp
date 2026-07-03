class Solution {
public:
    string longestPalindrome(string s) {
        
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));

        
        int currentMaxLength=1;
        int left=0;
        // setting it for the first single character palindromes to be 1,always,
        // and checking two character palindromes and also setting them to dp,these are building blocks for later ones
        for(int i=0;i< s.size();i++){
            dp[i][i]=1;
            if(i+1 < s.size()){
                if(s[i]==s[i+1]) { 

                    dp[i][i+1] = 1;
                    currentMaxLength=max(currentMaxLength,2);
                    left=i;
                }
                else dp[i][i+1] = 0;
            } 
        }

        for(int L = 2 ;L < s.size();L++){ // starting from 2,because we want 2 and more length
            for(int i=0;i <= s.size()-L;i++){ // this is because abcba ,if L=2 it should stop at abc,bcb,cba,and not go further because there is no more 3 Length substrings remaining
                int j = i + L ;
                if(s[i]==s[j] && dp[i+1][j-1]) { 
                    dp[i][j] = 1;
                    currentMaxLength=max(currentMaxLength,j-i+1);
                    left=i;
                }
                else dp[i][j] = 0;  
        }
    }
    return s.substr(left,currentMaxLength);
}
};