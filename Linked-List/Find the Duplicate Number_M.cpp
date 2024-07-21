//
// Created by muham on 21/07/2024.
//
// Commented on 21/07/24

#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(const std::vector<int>& nums) {
        int slow = 0, fast = 0;

        // Finding the intersection point of slow and fast
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        // Start slow_2 from the first index
        // The distance of slow to the cycle-causing node is equal to the distance of slow_2 from that cycle-causing node
        // That's a Floyd's proven theorem
        int slow_2 = 0;

        while (true) {
            slow = nums[slow];
            slow_2 = nums[slow_2];
            if (slow == slow_2) {
                return slow;
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << "Duplicate number: " << solution.findDuplicate(nums) << std::endl;  // Output: 2

    nums = {3, 1, 3, 4, 2};
    std::cout << "Duplicate number: " << solution.findDuplicate(nums) << std::endl;  // Output: 3

    return 0;
}
