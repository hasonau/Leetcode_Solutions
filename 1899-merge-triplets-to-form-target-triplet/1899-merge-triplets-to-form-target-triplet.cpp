class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int>indexesFound;
        for(int i=0;i<triplets.size();i++){
            int first=triplets[i][0];
            int second=triplets[i][1];
            int third=triplets[i][2];

            if(first>target[0] || second > target[1] || third > target[2]) continue;

            if(first==target[0]) indexesFound.insert(0);
            if(second==target[1]) indexesFound.insert(1); 
            if(third==target[2]) indexesFound.insert(2); 

            if(indexesFound.size()==3) return true;
        }
        return false;
    }
};