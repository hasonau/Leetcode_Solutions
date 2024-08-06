# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional,List
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # Helper function to validate the BST
        def isValid(root, lower, upper):
            # Base case: an empty node is always valid
            if not root:
                return True
            # If the node's value is not within the valid range, return False
            if not (lower < root.val < upper):
                return False
            # Recursively check the left and right subtrees
            return isValid(root.left, lower, root.val) and isValid(root.right, root.val, upper)

        # Initialize the recursion with the entire range of valid values
        return isValid(root, float("-infinity"), float("infinity"))


# Main function to test the isValidBST function
def main():
    # Create a test case tree
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)

    solution = Solution()

    # Test isValidBST function
    is_valid = solution.isValidBST(root)
    print("Is valid BST:", is_valid)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Solution class provides a method to check if a binary tree is a valid binary search tree (BST).
# The isValidBST method uses a helper function isValid to recursively check each node.
# It ensures that each node's value is within a valid range, updating the range as it traverses the tree.
# The main function creates a sample binary tree and tests the isValidBST method, printing the result.
