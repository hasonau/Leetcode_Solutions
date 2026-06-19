class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size() % groupSize) != 0) return false;

        map<int, int> freq;
        for (int num : hand) {
            freq[num]++;
        }
        
        while (!freq.empty()) {
            auto it = freq.begin(); // Always take smallest
            int start = it->first;
            
            // Try to form one group
            for (int i = 0; i < groupSize; i++) {
                int needed = start + i;
                auto it_curr = freq.find(needed);
                
                if (it_curr == freq.end()) return false; // Missing consecutive
                
                it_curr->second--;
                if (it_curr->second == 0) {
                    freq.erase(it_curr);
                }
            }
        }
        return true;
    }
};