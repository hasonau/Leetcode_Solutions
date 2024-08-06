# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 0
        res = 0

        # Helper function to perform inorder DFS
        def inorderDFS(root):
            nonlocal count, res
            if root:
                inorderDFS(root.left)
                count += 1
                if count == k:
                    res = root.val
                    return
                inorderDFS(root.right)
            return

        # Inorder traversal of the BST gives a sorted array
        inorderDFS(root)
        return res


# Main function to test the kthSmallest function
def main():
    # Create a test case tree
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)

    solution = Solution()

    # Test kthSmallest function for k = 1
    k = 3
    kth_smallest = solution.kthSmallest(root, k)
    print(f"{k}th smallest element:", kth_smallest)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Solution class provides a method to find the kth smallest element in a BST.
# The kthSmallest method uses an inorder DFS to traverse the tree in sorted order.
# The traversal stops early once the kth element is found, storing it in the res variable.
# The main function creates a sample binary tree and tests the kthSmallest method, printing the kth smallest element.
