//
// Created by muham on 13/07/2024.
//
// This code is written on 13/07/2024 by Umair and commented by GPT

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Solution class containing the characterReplacement method
class Solution {
public:
    // Method to find the length of the longest substring with at most k replacements
    int characterReplacement(string s, int k) {
        int left = 0; // Left pointer for the sliding window
        int max_length = 0; // Variable to store the maximum length of the substring
        unordered_map<char, int> char_frequencies; // Map to store the frequency of characters in the current window
        int max_count = 0; // Variable to store the maximum frequency of any character in the current window

        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); ++right) {
            char right_char = s[right]; // Character at the current right pointer
            char_frequencies[right_char]++; // Increment the frequency of the current character
            max_count = max(max_count, char_frequencies[right_char]); // Update the maximum frequency

            // If the current window size minus the max frequency is greater than k, shrink the window
            while ((right - left + 1) - max_count > k) {
                char left_char = s[left]; // Character at the current left pointer
                char_frequencies[left_char]--; // Decrement the frequency of the character at the left pointer
                left++; // Move the left pointer to the right
            }

            // Update the maximum length of the substring
            max_length = max(max_length, right - left + 1);
        }

        return max_length; // Return the maximum length of the substring
    }
};

int main() {
    Solution solution; // Create a Solution object
    string s = "AABABBA"; // Define the input string
    int k = 1; // Define the number of allowed replacements
    int result = solution.characterReplacement(s, k); // Call the characterReplacement method
    cout << "The length of the longest substring after " << k << " replacements is: " << result << endl; // Print the result
    return 0;
}
