class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> sumToIndices;
        int result = 0;

        sumToIndices[0] = -1;
        int k = 0;
        int runningSum = 0;
        for(auto [index,n] : std::views::enumerate(nums)){
            
            if(n == 0) n = -1;

            runningSum+=n;
            if(sumToIndices.contains(runningSum)) result = max(result,static_cast<int>(index - sumToIndices[runningSum]));

            if(!sumToIndices.contains(runningSum)) sumToIndices[runningSum] = index;
        }
        return result;
    }
};