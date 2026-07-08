class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int recursive(vector<vector<int>>& pairs, int index, int lastIndex){
        if(index >= n) return 0;
        if(memo[index][lastIndex+1] != -1) return memo[index][lastIndex+1];

        int take = 0;
        if(lastIndex == -1 || pairs[lastIndex][1] < pairs[index][0]) {
            take = 1 + recursive(pairs, index+1, index);
        }
        int skip = recursive(pairs, index+1, lastIndex);

        return memo[index][lastIndex+1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        memo.assign(n, vector<int>(n+1, -1));
        return recursive(pairs, 0, -1);
    }
};