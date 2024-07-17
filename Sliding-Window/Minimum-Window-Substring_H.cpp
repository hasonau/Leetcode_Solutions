//
// Created by muham on 17/07/2024.
//
#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> hashMap1;
        for (char char_t : t) {
            hashMap1[char_t]++;
        }

        pair<int, int> result_pointers = {-1, -1};
        int window_size = INT_MAX;
        int count = 0;
        int left = 0;
        int need = t.size();
        unordered_map<char, int> char_frequency;

        for (int right = 0; right < s.size(); ++right) {
            if (hashMap1.count(s[right])) {
                char_frequency[s[right]]++;
                if (char_frequency[s[right]] <= hashMap1[s[right]]) {
                    count++;
                }

                while (count == need) {
                    if (right - left + 1 < window_size) {
                        result_pointers = {left, right};
                        window_size = right - left + 1;
                    }

                    if (count == need) {
                        char_frequency[s[left]]--;
                    }

                    if (hashMap1.count(s[left]) && char_frequency[s[left]] < hashMap1[s[left]]) {
                        count--;
                    }
                    left++;
                }
            }
        }

        if (window_size != INT_MAX) {
            return s.substr(result_pointers.first, result_pointers.second - result_pointers.first + 1);
        }

        return "";
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution solution;
    string result = solution.minWindow(s, t);
    cout << "The minimum window substring is: " << result << endl;
    return 0;
}