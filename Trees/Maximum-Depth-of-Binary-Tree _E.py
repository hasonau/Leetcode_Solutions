from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
            # edge case and base case as well,when tree is empty
            if not root:
                return 0
            return max(1+self.maxDepth(root.left),1+self.maxDepth(root.right))

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
