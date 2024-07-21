# Commented on 21/07/24

from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = fast = 0

        # Finding the intersection point of slow and fast
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break

        # Start slow_2 from the first index
        # The distance of slow to the cycle-causing node is equal to the distance of slow_2 from that cycle-causing node
        # That's a Floyd's proven theorem
        slow_2 = 0

        while True:
            slow = nums[slow]
            slow_2 = nums[slow_2]
            if slow == slow_2:
                return slow

def main():
    solution = Solution()
    nums = [1, 3, 4, 2, 2]
    print("Duplicate number:", solution.findDuplicate(nums))  # Output: 2

    nums = [3, 1, 3, 4, 2]
    print("Duplicate number:", solution.findDuplicate(nums))  # Output: 3

if __name__ == "__main__":
    main()
