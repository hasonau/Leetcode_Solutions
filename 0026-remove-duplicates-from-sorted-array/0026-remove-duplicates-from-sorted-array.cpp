class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int left=1;
         int right=1;

         for (right;right<nums.size();right++){
            if (nums[right]==nums[right-1]){
                continue;
            }
            else{
                nums[left]=nums[right];
                left++;
            }
         }
         return left;
    }
}; 