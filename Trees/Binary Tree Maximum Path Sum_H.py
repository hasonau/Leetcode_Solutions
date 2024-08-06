# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maximum = [float("-inf")]  # Initialize maximum to the smallest possible value

        def dfs_helper(root):
            if not root:
                return 0  # Base case: if the node is None, return 0

            # Recursively get the maximum path sum for left and right subtrees
            leftSubTree = dfs_helper(root.left)
            rightSubTree = dfs_helper(root.right)

            # Calculate current tree path sum which includes the root node
            currTree = leftSubTree + rightSubTree + root.val

            # Determine the maximum path sum including the root node, but only one side of the tree (either left or right)
            betterPath = max(leftSubTree, rightSubTree) + root.val
            # Update the global maximum path sum
            maximum[0] = max(currTree, betterPath, maximum[0])

            # Return the best path sum including the current node and one side of the tree
            return betterPath if betterPath > 0 else 0

        dfs_helper(root)
        return maximum[0]


# Main function to test the maxPathSum function
def main():
    # Create a test case tree
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)

    solution = Solution()

    # Test maxPathSum function
    max_path_sum = solution.maxPathSum(root)
    print("Maximum Path Sum:", max_path_sum)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Solution class provides a method to find the maximum path sum in a binary tree.
# The maxPathSum method uses a helper function dfs_helper to recursively compute the maximum path sum.
# The helper function considers both the path that includes the current node and both its subtrees, and the path that only includes one subtree.
# The maximum path sum is updated globally, and the best path sum including the current node is returned.
# The main function creates a sample binary tree and tests the maxPathSum method, printing the maximum path sum.
