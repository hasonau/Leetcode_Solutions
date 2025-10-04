class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int mid;
    // 4,5,6,7,0,1,2 
        while(l<=r){
            mid=l+(r-l)/2;
            // we are in left side
            if (nums[mid]==target) return mid;
            cout<<"nums mid"<<nums[mid]<<endl;
            cout<<"nums l"<<nums[l]<<endl;
            cout<<"nums r"<<nums[r]<<endl;
            if(nums[l]<=nums[mid]){
                if(target > nums[mid] || target < nums[l]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            else{
                if(target > nums[r] || target < nums[mid]) r=mid-1;
                else l=mid+1;
            }
        }
        return -1;
    }
};