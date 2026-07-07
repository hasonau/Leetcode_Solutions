class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int t[2501];
        // memset(t,1,sizeof(t));
        fill(t, t + 2501, 1);

        int maxResult=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && t[j]+1 > t[i]) t[i] = t[j]+1;
            }
            maxResult= max(maxResult,t[i]);
        }
        return maxResult;
    }
};