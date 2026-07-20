class Solution {
public:
    int half;
    int t[201][20001];
    bool recursive(int i,int currentSum,vector<int>& nums){
        if(currentSum==half) return true;
        if(i>=nums.size()) return false;

        if(t[i][currentSum]!=-1) return t[i][currentSum];

        bool take = recursive(i+1,currentSum+nums[i],nums);
        bool skip = recursive(i+1,currentSum,nums);

        return  t[i][currentSum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int totalProduct=0;
        for(int n:nums){
            totalProduct +=n;
        }

        if(totalProduct%2!=0) return false;
        memset(t,-1,sizeof(t));
        half = totalProduct/2;

        return recursive(0,0,nums);
    }
};