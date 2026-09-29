class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> leftPrefixSum(n + 1);
        vector<int> rightPrefixSum(n + 1);

        for (int i = 1; i <= n; i++) {
            leftPrefixSum[i] = leftPrefixSum[i - 1] + nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            rightPrefixSum[i] = rightPrefixSum[i + 1] + nums[i];
        }

        for(int i= 0;i < n;i++){
            if(leftPrefixSum[i] == rightPrefixSum[i+1]) return i;
        }
        return -1;

    }
};