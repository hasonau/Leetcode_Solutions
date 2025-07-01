class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // two pointers approach using three pointers actually
        set<vector<int>> triplets;

        for (int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;

            sort(nums.begin(),nums.end());
            while(left<right){

                if ((nums[left]+nums[right])< -nums[i]){
                    left+=1;
                }
                else if ((nums[left]+nums[right])>-nums[i]) {
                    right-=1;
                }
                else{
                    triplets.insert({nums[i],nums[left],nums[right]});
                    // in order to avoid infinite loops,we need to move both pointers 
                    // so no duplicate keeps it stuck here
                    left++;
                    right--;
                }
            }   
        }
        vector<vector<int>>result(triplets.begin(), triplets.end());
        return result;
    }
};