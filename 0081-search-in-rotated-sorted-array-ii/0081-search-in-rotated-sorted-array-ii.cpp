class Solution {
public:
    bool binarySearch(vector<int>& nums,int left,int right,int target){
        int mid;
        while(left<=right){
            mid= left+(right-left)/2;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]<target) left=mid+1;
            else return true; 
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1) return target==nums[0];
        int i=1;
        bool pivotFound =false;
        int pivot=nums.size()-1;
        while(i<nums.size()){
            if(nums[i]<nums[i-1]) {
                pivot=i;
                pivotFound=true;
                break;
            }
            i++;
        }
        if (pivotFound) return binarySearch(nums,0,pivot-1,target) || binarySearch(nums,pivot,nums.size()-1,target);
        else return binarySearch(nums,0,nums.size()-1,target);
    }
};