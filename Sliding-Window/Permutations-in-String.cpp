//
// Created by muham on 16/07/2024.
//
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        unordered_map<char, int> hashMap;

        // Calculate character frequencies in s1
        for (char s : s1) {
            hashMap[s] += 1;
        }

        unordered_map<char, int> char_frequency;

        for (int right = 0; right < s2.size(); ++right) {
            if (hashMap.find(s2[right]) != hashMap.end()) {
                char_frequency[s2[right]] += 1;

                while (char_frequency[s2[right]] > hashMap[s2[right]]) {
                    char_frequency[s2[left]] -= 1;
                    if (char_frequency[s2[left]] == 0) {
                        char_frequency.erase(s2[left]);
                    }
                    left += 1;
                }

                if ((right - left + 1) == s1.size()) {
                    return true;
                }
            } else {
                left = right + 1;
                char_frequency.clear();
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "abc";
    s2 = "ccccbbbbaaaa";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 0 (false)

    s1 = "adc";
    s2 = "dcda";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "hello";
    s2 = "ooolleoooleh";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 0 (false)

    s1 = "a";
    s2 = "ab";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "abcd";
    s2 = "dcba";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "abcd";
    s2 = "efghijklmnop";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 0 (false)

    s1 = "abc";
    s2 = "cbaebabacd";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "xyz";
    s2 = "zxyyzyx";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    s1 = "a";
    s2 = "a";
    cout << "checkInclusion('" << s1 << "', '" << s2 << "') = " << solution.checkInclusion(s1, s2) << endl;  // Expected output: 1 (true)

    return 0;
}
