class Solution {
public:
    
    int recursive(int index,vector<int> &cost,int n){
        // base case,means,we have already reached the top,return 0
        if(index >= n) return 0;

        // // help of memoized values
        if(dp.find(index)!=dp.end()) return dp[index];
        
        // // memoization step
        dp[index]= cost[index] + min(recursive(index+1,cost,n),recursive(index+2,cost,n));

        return dp[index];
        return cost[index] + min(recursive(index+1,cost,n),recursive(index+2,cost,n));
    }


    unordered_map<int,int>dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int index = 0;
        return min(recursive(index,cost,n),recursive(index+1,cost,n));
    }
};