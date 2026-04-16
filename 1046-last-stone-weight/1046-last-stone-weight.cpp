class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1){
            int y= stones.back(); stones.pop_back();
            int x= stones.back();stones.pop_back(); 
            int diff = abs(y - x);
            if(x<y) {
                    auto it = lower_bound(stones.begin(), stones.end(), diff);
                    stones.insert(it, diff);
            }
        }
        stones.push_back(0);
        return stones[0];
    }
};