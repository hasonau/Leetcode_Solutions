class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashmap;
        vector <int>result;
        for (int i=0 ;i<nums.size();i++){
            if (hashmap.find(target-nums[i])!=hashmap.end()){
                result.push_back(i);
                result.push_back(hashmap[target-nums[i]]);
                return result;
            }
            else {
                hashmap[nums[i]]=i;
            }
        }
        return result;
    }

};