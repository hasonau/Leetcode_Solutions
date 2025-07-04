class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()==1){
            return false;
        }
        unordered_map<int,int>duplicateChecker;
        for(int i=0;i<=nums.size();i++){
            if(duplicateChecker.find(nums[i])==duplicateChecker.end()){
                duplicateChecker[nums[i]]=i;
            }
            else{
                if(abs(i-duplicateChecker[nums[i]])<=k){
                    return true;
                }
                else{
                    duplicateChecker[nums[i]]=i;
                }
            }
        }
        return false;
    }
};