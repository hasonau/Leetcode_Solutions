class Solution {
public:
     vector<int>dp = vector<int>(46,-1);
     int recursive(int i,int n){
        if(i==n) return 1;

        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i] = recursive(i+1,n)+recursive(i+2,n);

    }
    int climbStairs(int n) {
        return recursive(0,n);
    }
};