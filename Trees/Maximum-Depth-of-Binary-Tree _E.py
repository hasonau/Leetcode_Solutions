from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Edge case: if the tree is empty
        if not root:
            return 0

        # Base case: if the node is a leaf node
        if not root.right and not root.left:
            return 1

        # Recursively find the depth of the left and right subtrees
        leftSide = 1 + self.maxDepth(root.left) if root.left else float("-inf")
        rightSide = 1 + self.maxDepth(root.right) if root.right else float("-inf")

        # Return the maximum depth from the left and right subtrees
        return max(leftSide, rightSide)

# Main function for testing
def main():
    # Creating a sample tree
    #       1
    #      / \
    #     2   3
    #    /
    #   4
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)

    solution = Solution()
    print("Max Depth of the Tree:", solution.maxDepth(root))  # Output should be 3

if __name__ == "__main__":
    main()
