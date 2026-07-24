class Solution {
public:
    int targetSum;
    unordered_map<int,int>hashmap;

    pair<int,int> recursive(int i,vector<int>& nums){
        if(hashmap.find(targetSum - nums[i])!=hashmap.end()) return {i,hashmap[targetSum-nums[i]]};
        hashmap[nums[i]] = i;
        return recursive(i+1,nums);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        targetSum=target;
        auto result = recursive(0,nums);
        return {result.first,result.second};
    }
};