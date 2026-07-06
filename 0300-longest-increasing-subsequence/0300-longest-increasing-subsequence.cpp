class Solution {
public:
    int t[2501][2501];
    int recursive(vector<int>& nums,int i,int lastInd){
        // base case
        if(i>=nums.size()) return 0;

        int left=0,right=0;
        if(t[i][lastInd+1]!=-1) return t[i][lastInd+1];
        // only take when value is greater than the last value we considered
        if(lastInd==-1 || nums[i] > nums[lastInd]) left= 1 + recursive(nums,i+1,i);
        // skip is called anyways,for both cases,even if value is greater or not,skip will still be called
        right = recursive(nums,i+1,lastInd);

        return  t[i][lastInd+1] = max(left,right);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        if(nums.size()==1) return 1;
        return recursive(nums,0,-1);
    }
};