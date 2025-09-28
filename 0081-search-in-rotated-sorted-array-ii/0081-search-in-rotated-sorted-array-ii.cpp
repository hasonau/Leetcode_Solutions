class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid;

        while(l<=r){
            mid=(l+r)/2;
            
            if(target==nums[mid]) return true;
            if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
                continue; // skip the rest of this iteration
            }
            
            // it means we are in left side of our array
            if(nums[mid]>=nums[l]){
                if(target > nums[mid] || target < nums[l]) l=mid+1;
                else r=mid-1;
            }
            // we are in Right portion of our array
            else{
                if(target < nums[mid] || target > nums[r]) r=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};