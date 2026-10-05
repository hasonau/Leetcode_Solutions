class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> prefixFreq;
        int count = 0;

        prefixFreq[0]++;

        int prefixSum = 0;
        for(auto [i,n] : std::views::enumerate(nums)){

            prefixSum+=n;
            if(prefixFreq.contains(prefixSum - k)) count+=prefixFreq[prefixSum-k];

            prefixFreq[prefixSum]++;
        }
        return count;
    }
};