// BOTTOM UP APPROACH,DP
class Solution {
public:
    int rob(vector<int>& nums) {

    int dp[]={0,0,nums[nums.size()-1]};
    int i=nums.size()-2;
    while(i>=0){
        int temp= nums[i]+ max(dp[0],dp[1]);
        dp[0]=dp[1];
        dp[1]=dp[2];
        dp[2]=temp;
        i--;
    }
        return max(dp[1],dp[2]);
    }
};