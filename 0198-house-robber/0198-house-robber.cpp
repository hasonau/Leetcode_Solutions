class Solution {
public:
    int rob(vector<int>& nums) {
        int left=0;
        int right=0;
        int i=nums.size()-1;

        while(i>=0){
            int temp=max(right+nums[i],left);
            right= left;
            left=temp;
            i--;
        }
        return left;
    }
};