// Three solutions are :
//1. hashmap freq table + getting key,value pair + sorting based on value(frequency)
// 2. this one,two hashmaps one for group by freq,second for freq_map
// 3. third is heap solution

// all are feasible but i did the one which i thought is the fastest
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, unordered_set<char>> group_by_frequency;
        unordered_map<char, int> frequency_map;

        int max_freq = 0;

        // Build frequency buckets
        for (char ch : s) {
            int old_freq = frequency_map[ch];

            if (old_freq > 0) {
                group_by_frequency[old_freq].erase(ch);
            }

            int new_freq = ++frequency_map[ch];
            group_by_frequency[new_freq].insert(ch);

            max_freq = max(max_freq, new_freq);
        }

        // highest frequency to lowest
        string result;

        for (int freq = max_freq; freq >= 1; freq--) {
            for (char ch : group_by_frequency[freq]) {
                result.append(freq, ch);
            }
        }

        return result;
    }
};
