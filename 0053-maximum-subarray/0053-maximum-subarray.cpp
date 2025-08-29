class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,j=0;
        int currSum;
        int maxResult= std::numeric_limits<int>::min();

        while(j<nums.size()){
            currSum+=nums[j];
            if(currSum<=0){
                maxResult=max(maxResult,currSum);
                currSum=0;
                i=j+1;
            }
        if(currSum!=0 && currSum>maxResult){
            maxResult=currSum;
        }
        j++;
        }
        return maxResult;
    }
};