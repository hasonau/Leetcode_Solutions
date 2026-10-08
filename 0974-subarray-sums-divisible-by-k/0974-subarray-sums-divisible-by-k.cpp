class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> sumToIndices;
        
        sumToIndices[0] = 1;
        int runningSum=0;
        int count = 0;

        for(auto [currentIndex,value] : std::views::enumerate(nums)){
            
            runningSum += value;

            // Purpose: Normalize the remainder so it is always between 0 and k - 1.
            //     - runningSum % k can be negative in C++.
            //     - + k fixes negative remainders.
            //     - The final % k fixes the case where adding k makes a positive remainder too large.
            int rem = ((runningSum % k) + k) % k;

            if(sumToIndices.contains(rem)){
                count+=sumToIndices[rem];
            }
            
           sumToIndices[rem]+=1;
        }
        return count;
    }
};