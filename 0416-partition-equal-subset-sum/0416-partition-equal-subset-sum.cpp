class Solution {
public:
    int half;
    int t[201][20001];
    bool recursive(int i,int currentSum,vector<int>& nums){
        if(i>= nums.size()) return 0;
        if(currentSum == half) return 1;
        if(t[i][currentSum]!=-1) return t[i][currentSum];

        int take=0;
        if(nums[i]+currentSum <= half) take = recursive(i+1,currentSum+nums[i],nums);

        int skip = recursive(i+1,currentSum,nums);

        return t[i][currentSum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        memset(t,-1,sizeof(t));
        for(int n : nums){
            total+=n;
        }
        if(total % 2==1) return false;
        half = total/ 2 ;
        return recursive(0,0,nums);
    }
};