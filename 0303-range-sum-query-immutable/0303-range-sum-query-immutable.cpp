class NumArray {
public:
    vector<int> prefixSum = vector<int>(10001);

    NumArray(vector<int>& nums) {
        for(int i = 1;i <= nums.size();i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1]; 
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

