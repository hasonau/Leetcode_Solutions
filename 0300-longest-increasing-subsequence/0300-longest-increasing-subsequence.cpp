class Solution {
public:
    int t[2501][2501];
    int recursive(int i,int prevIndex,vector<int>& nums){
        if(i>= nums.size()) return 0;
        
        if(prevIndex!=-1 && t[i][prevIndex+1]!=-1) return t[i][prevIndex+1];
        int take=0;
        if(prevIndex==-1 || nums[i]>nums[prevIndex]) take = 1 + recursive(i+1,i,nums);

        int skip = recursive(i+1,prevIndex,nums);

        return t[i][prevIndex+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        memset(t,-1,sizeof(t));

        return recursive(0,-1,nums);
    }
};