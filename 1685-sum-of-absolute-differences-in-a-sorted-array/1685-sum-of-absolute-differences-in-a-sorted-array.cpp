class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum =0;

        for (int n : nums) totalSum+=n;

        vector<int>result(nums.size());
        vector<int>leftprefixSum(nums.size() + 1);
        vector<int>rightprefixSum(nums.size() + 1);

        // identity of additive binary opeartion (+) is 0 
        leftprefixSum[0] = 0;
        rightprefixSum[0] = 0;

        // prefixSum construction before the important loop
        for(int i = 1; i <= nums.size() ; i++){
            leftprefixSum[i] = leftprefixSum[i-1] + nums[i-1];
        }

      for(int i = nums.size() - 1; i >= 0; i--){
            rightprefixSum[i] = rightprefixSum[i+1] + nums[i];
        }

        for(int i = 0 ; i < nums.size(); i++){

            int rightPrefixSum = totalSum - leftprefixSum[i] - nums[i];
            int leftPrefixSum = totalSum - rightprefixSum[i+1] - nums[i];
            
            // long long leftSide =  abs(nums[i]*(i+1) - leftPrefixSum);
            long long leftSide = abs(1LL * nums[i] * (i) - leftPrefixSum);
            long long n = nums.size();

            long long rightSide = abs(
                1LL * nums[i] * (n - 1 - i) - rightPrefixSum
            );


            result[i] = leftSide + rightSide;
        }
        return result;
    }
};