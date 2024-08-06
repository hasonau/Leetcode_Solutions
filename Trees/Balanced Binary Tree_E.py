# Definition for a binary tree node.
from typing import List,Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # Initialize the answer as True, assuming the tree is balanced
        answer = True
        # A set to hold the valid height differences (1, 0, -1)
        hashmap = {1, 0, -1}

        def dfs(root):
            if not root:
                return 0
            nonlocal answer
            # Calculate the height of the left subtree
            leftside = 1 + dfs(root.left) if root.left else 0
            # Calculate the height of the right subtree
            rightside = 1 + dfs(root.right) if root.right else 0

            # If the difference in heights is not in the valid set, mark answer as False
            if (leftside - rightside) not in hashmap:
                answer = False
            # Set the current node's value to the maximum height of its subtrees
            root.val = max(leftside, rightside)
            return root.val

        dfs(root)
        return answer


# Main function to test the isBalanced method
if __name__ == "__main__":
    # Creating a sample binary tree
    # Tree:
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    # Create a Solution object
    solution = Solution()
    # Check if the tree is balanced
    result = solution.isBalanced(root)
    print("Is the tree balanced?", result)  # Output should be True

# Date: 2024-08-06
