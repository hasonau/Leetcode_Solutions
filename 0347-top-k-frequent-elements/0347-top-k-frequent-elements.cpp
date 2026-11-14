// the actual bucket sort,done in two phases
// the counting phase 
// and the grouping phase
// my previous solution was correct but was doing dynamically extra work of 
// jumping same value from here to there,this is simpler,although it uses more memory
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, vector<int>> group_by_frequency;
        unordered_map<int, int> frequency_map;

        int max_freq = 0;

        for(int n : nums){
            int new_freq = ++frequency_map[n];
            max_freq = max(max_freq, new_freq);
        }

        // Group numbers by their final frequency
        for(auto [n, freq] : frequency_map){
            group_by_frequency[freq].push_back(n);
        }

        vector<int> result;
        while (max_freq > 0 && result.size() < k) {

            if (group_by_frequency.contains(max_freq)) {
                for (int n : group_by_frequency[max_freq]) {
                    result.push_back(n);
                }
            }
            max_freq--;
        }

        return result;
    }
};