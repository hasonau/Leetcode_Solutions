class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        // frequencies of all elements has been recorded in hashmap
        for (int i=0;i<nums.size();i++){
            if(hashmap.find(nums[i])!=hashmap.end()){
                hashmap[nums[i]]+=1;
            }
            else{
                hashmap[nums[i]]=1;
            }
        }

        // now we take out the pairs,and place in sortingRelatedVector vector,
        vector<pair<int, int>> sortingRelatedVector;
        for(const auto &pair:hashmap){
            sortingRelatedVector.push_back({pair.second,pair.first});
        }

        // now we need to sort it,we call the sorting method on it
        sort(sortingRelatedVector.rbegin(),sortingRelatedVector.rend());
        // this sorting changes the original vector
        // now we only push the the second value of first k elements 

        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(sortingRelatedVector[i].second);
        }

        return result;



    }
};