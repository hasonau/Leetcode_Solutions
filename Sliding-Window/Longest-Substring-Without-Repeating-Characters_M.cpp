//
// Created by muham on 11/07/2024.
//
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> my_set;
    int l = 0, r = 0, result = 0;

    for (char ch : s) {
        while (my_set.find(ch) != my_set.end()) {
            my_set.erase(s[l]);
            l++;
        }
        my_set.insert(ch);
        r++;
        result = max(result, r - l);
    }

    return result;
}

int main() {
    string input = "abcabcbb";
    cout << lengthOfLongestSubstring(input) << endl;  // Output: 3

    return 0;
}
