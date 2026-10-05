class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> prefixFreq;
        int count = 0;

        vector<int>prefixSum(nums.size()+1);
        prefixSum[0]=0;
        prefixFreq[0]++;

        for(auto [i,n] : std::views::enumerate(nums)){

            prefixSum[i+1] = prefixSum[i] + n;
            int s = prefixSum[i+1];
            if(prefixFreq.contains(s - k)) count+=prefixFreq[s-k];

            prefixFreq[s]++;
        }
        return count;
    }
};