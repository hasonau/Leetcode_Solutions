class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for(int n : nums){
            if(seen.contains(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};