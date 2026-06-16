class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int result=INT_MIN;
        for(auto n : nums){
            sum+=n;
            result=max(result,sum);
            if(sum<0) sum=0;
        }
        return result;
    }
};