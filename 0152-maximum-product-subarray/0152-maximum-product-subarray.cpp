class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxProduct = max(maxProduct,nums[i]);
            if(nums[i]==0) continue;
            int currentProduct = nums[i];
            for(int j=i+1;j<nums.size();j++){
                currentProduct = currentProduct*nums[j];
                maxProduct =max(currentProduct,maxProduct);
            }
        }
        return maxProduct;
    }
};