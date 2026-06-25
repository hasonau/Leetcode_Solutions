//  Bottom up approach,DP
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int dp[] = {cost[cost.size()-2],cost[cost.size()-1]};
        int i = cost.size()-3;
        while(i>=0){
            int temp=dp[0];
            dp[0] = min(dp[0],dp[1]) + cost[i];
            dp[1] = temp;
            i--;
        }
        return min(dp[0],dp[1]);
    }
};