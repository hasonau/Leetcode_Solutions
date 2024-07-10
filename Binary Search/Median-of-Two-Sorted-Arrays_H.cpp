//
// Created by muham on 10/07/2024.
//
// Commented by GPT on date 10/7/2024

// This algorithm finds the median of two sorted arrays by performing a binary search on the smaller array.
// It partitions both arrays such that the left partition contains the same number of (or one more) elements than the right partition.
// It then determines the median based on the maximum element on the left and the minimum element on the right.

// Header files needed for the algorithm
#include <vector>
#include <iostream>
#include <algorithm> // For std::min and std::max
#include <climits>   // For INT_MIN and INT_MAX

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Using pointers to vector<int> to make sure A is the smaller array
        std::vector<int>* A = &nums1;
        std::vector<int>* B = &nums2;

        // Total number of elements in both arrays
        int total = nums1.size() + nums2.size();
        // Half is used to determine the partition point
        int half = (total + 1) / 2;

        // Ensure A is the smaller array for easier binary search
        if (nums1.size() > nums2.size()) {
            std::vector<int>* temp = A;
            A = B;
            B = temp;
        }

        // Binary search range
        int l = 0;
        int h = A->size(); // This is initialized to the size of the smaller array
        int m = 0; // Middle index
        double result;

        while (l <= h) {
            // Middle of the current binary search range
            m = (l + h) / 2;
            // j is calculated such that the total elements on the left side of the partition is half
            int j = half - m;

            // Elements on the left and right of the partition in A
            int Aleft = (m - 1 >= 0) ? (*A)[m - 1] : INT_MIN;
            int ARight = (m < A->size()) ? (*A)[m] : INT_MAX;

            // Elements on the left and right of the partition in B
            int Bleft = (j - 1 >= 0) ? (*B)[j - 1] : INT_MIN;
            int BRight = (j < B->size()) ? (*B)[j] : INT_MAX;

            // Adjust the binary search range based on the partitioning
            if (Aleft > BRight) {
                h = m - 1; // Move the partition left in A
            } else if (Bleft > ARight) {
                l = m + 1; // Move the partition right in A
            } else {
                // Found the correct partition
                if (total % 2 == 1) {
                    // If the total number of elements is odd, return the max of left elements
                    result = std::max(Aleft, Bleft);
                } else {
                    // If the total number of elements is even, return the average of the middle two elements
                    result = (std::min(ARight, BRight) + std::max(Aleft, Bleft)) / 2.0;
                }
                break; // Exit the loop as we have found the median
            }
        }
        // Return the calculated median
        return result;
    }
};
int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << sol.findMedianSortedArrays(nums1, nums2) <<std::endl;
    return 0;
}