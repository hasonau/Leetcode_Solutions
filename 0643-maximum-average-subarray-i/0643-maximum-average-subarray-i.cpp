class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int currSum=0;
        double maxResult = -std::numeric_limits<double>::max(); // largest negative finite double
        while (j<nums.size()){
            if(j-i+1==k){
                currSum+=nums[j];
                maxResult= max((double)currSum/k,maxResult);
                currSum-=nums[i];
                i++;
            }
            else{
                currSum+=nums[j];
            }
            j++;
        }
        return maxResult;
    }
};