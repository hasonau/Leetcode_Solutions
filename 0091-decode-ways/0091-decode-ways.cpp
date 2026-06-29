class Solution {
public:

    vector<int> dp;

    int recursive(int index, string &s){
        if(index == s.size()) return 1;

        if(dp[index] != -1) return dp[index];

        // invalid case
        if(s[index] == '0') return dp[index] = 0;

        int result = 0;

        result += recursive(index + 1, s);

        if(index + 1 < s.size()) {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if(num >= 10 && num <= 26) {
                result += recursive(index + 2, s);
            }
        }

        return dp[index] = result;
    }

    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n + 1, -1);
        return recursive(0, s);
    }
};