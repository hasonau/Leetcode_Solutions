from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # Using a list to store the result since integers can't be modified within a nested function without being declared nonlocal
        result = [0]

        def dfs(node):
            if not node:
                return 0

            # Calculate the depth of the left and right subtrees
            leftside = (1 + dfs(node.left)) if node.left else 0
            rightside = (1 + dfs(node.right)) if node.right else 0

            # Update the result with the maximum diameter found so far
            result[0] = max(result[0], leftside + rightside)

            # Return the maximum depth of the current node's subtrees
            return max(leftside, rightside)

        # Start the DFS traversal from the root
        dfs(root)

        # Return the diameter of the binary tree
        return result[0]


# Main function to test the Solution class
if __name__ == "__main__":
    # Construct the binary tree
    # Example:
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

    solution = Solution()
    result = solution.diameterOfBinaryTree(root)

    # Expected output: 3 (The path is 4 -> 2 -> 1 -> 3 or 5 -> 2 -> 1 -> 3)
    print("Diameter of the binary tree:", result)

# Date: 2024-08-06
# from clion