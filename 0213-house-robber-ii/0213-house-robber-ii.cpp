
 // BOTTOM UP APPROACH,DP
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int right= 0;
        int left =0;
        int i=nums.size()-2;
        while(i>=0){
            int temp= max(nums[i]+ right, left);
            right=left;
            left=temp;
            i--;
        }
        int firstResult = max(right,left);

        i=nums.size()-1;
        left=0;
        right=0;
        while(i>=1){
            int temp= max(nums[i]+ right, left);
            right=left;
            left=temp;
            i--;
        }    
        int secondResult = max(right,left);
        return max(firstResult,secondResult);
    }
}; 