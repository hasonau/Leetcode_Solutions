class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int>result;

        for(int n : nums1){
            map[n]+=1;
        }
        
        for(int n : nums2){
            if(map.contains(n)){
                result.push_back(n);
                map[n]-=1;
                if (map[n] == 0) map.erase(n);
            }
        }
        return result;
    }
};