# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if (not p or not q) or (p.val != q.val):
            return False
        # Recursive call to check left and right subtrees
        return self.sameTree(p.left, q.left) and self.sameTree(p.right, q.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
            # Check if the current tree and subRoot are the same
        if self.sameTree(root, subRoot):
            return True
        # Recursive call to check left and right subtrees
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


# Main function to test the isSubtree function
def main():
    # Create test case trees
    tree1 = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2)), TreeNode(5))
    subTree1 = TreeNode(4, TreeNode(1), TreeNode(2))

    tree2 = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(2, TreeNode(0))), TreeNode(5))
    subTree2 = TreeNode(4, TreeNode(1), TreeNode(2))

    solution = Solution()

    # Test case 1: Subtree is a subtree
    print("Test case 1 - Expected: True, Actual:", solution.isSubtree(tree1, subTree1))

    # Test case 2: Subtree is not a subtree
    print("Test case 2 - Expected: False, Actual:", solution.isSubtree(tree2, subTree2))


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The isSubtree function checks if a given tree (subRoot) is a subtree of another tree (root).
# It first checks if the current nodes of root and subRoot are the same using the sameTree function.
# If not, it recursively checks the left and right subtrees of root.
# The sameTree function is used to determine if two trees are identical.
