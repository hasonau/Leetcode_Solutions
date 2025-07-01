class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hashmap;

        for (int i = 0; i < strs.size(); i++) {
            string originalString = strs[i];
            sort(strs[i].begin(), strs[i].end());
            hashmap[strs[i]].push_back(originalString);
            // good practice to preserve strs the same it was given to me,it can be skipped,
            // but better to have
            strs[i]=originalString;
        }
        vector<vector<string>> result;
        for (const auto& pair : hashmap) {
            result.push_back(pair.second);
        }
        return result;
    }
};