class Solution {
public:
    int findMin(vector<int>& nums) {
            // early return for not rotated array
    if(nums.size()==1) return nums[0];
    if(nums[0]<nums[nums.size()-1]) return nums[0];

    
    int l=0;
    int r=nums.size()-1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;
        // cout<<"numsMID is :"<<nums[mid]<<endl;
        if(nums[mid] < ((mid-1)>=0 ? nums[mid-1] : INT_MIN)) return nums[mid];
        if(nums[mid] > ((mid+1)<=nums.size()-1 ? nums[mid+1] : INT_MAX)) return nums[mid+1];
        
        if(nums[mid]>=nums[l]) l=mid+1;
        else r=mid-1;

    }
    
    return -1;
    }
};