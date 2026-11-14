class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, unordered_set<int>> group_by_frequency;
        unordered_map<int, int> frequency_map;

        int max_freq =  0;

        for(int n : nums){
            int old_freq = frequency_map[n];

            // we remove it from it's previous location,whenever it was somewhere else,it 
            // means now it's count increase so it should go in that  bucket
            if(old_freq > 0){
                group_by_frequency[old_freq].erase(n);
            }

            int new_freq = ++old_freq;
            group_by_frequency[new_freq].insert(n);
            frequency_map[n] = new_freq;
            max_freq = max(max_freq, new_freq);
        }

        vector<int>result;
        while(true){
            if(group_by_frequency.contains(max_freq)){
                for (int n : group_by_frequency[max_freq]) {
                        result.push_back(n);
                    }
                    if(result.size() == k) break;
            }
            max_freq--;
            if(max_freq == 0) break;
        }

        return result;
    }
};
