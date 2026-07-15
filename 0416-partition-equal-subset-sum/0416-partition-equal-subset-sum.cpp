class Solution {
public:
    int half;
    int t[201][20001];
    bool recursive(int n,int currentSum,vector<int>& nums){
        if(n==0) return 0;
        if(currentSum == half) return 1;
        if(t[n-1][currentSum]!=-1) return t[n-1][currentSum];

        int take=0;
        if(nums[n-1]+currentSum <= half) take = recursive(n-1,currentSum+nums[n-1],nums);

        int skip = recursive(n-1,currentSum,nums);

        return t[n-1][currentSum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        memset(t,-1,sizeof(t));
        for(int n : nums){
            total+=n;
        }
        if(total % 2==1) return false;
        half = total/ 2 ;
        return recursive(nums.size(),0,nums);
    }
};