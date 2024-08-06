# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        result = True

        def dfs(p, q):
            if p and q:
                nonlocal result
                if p.left and q.left:
                    dfs(p.left, q.left)
                else:
                    if p.left or q.left:
                        result = False
                    else:
                        if p.val != q.val:
                            result = False
                if p.right and q.right:
                    dfs(p.right, q.right)
                else:
                    if p.right or q.right:
                        result = False
                    else:
                        if p.val != q.val:
                            result = False
            else:
                if not p:
                    if not q:
                        return
                    else:
                        result = False
                elif not q:
                    result = False
                else:
                    pass

        dfs(p, q)
        return result


# Main function to test the isSameTree function
def main():
    # Create test case trees
    tree1 = TreeNode(1, TreeNode(2), TreeNode(3))
    tree2 = TreeNode(1, TreeNode(2), TreeNode(3))

    tree3 = TreeNode(1, TreeNode(2), None)
    tree4 = TreeNode(1, None, TreeNode(2))

    solution = Solution()

    # Test case 1: Trees are the same
    print("Test case 1 - Expected: True, Actual:", solution.isSameTree(tree1, tree2))

    # Test case 2: Trees are different
    print("Test case 2 - Expected: False, Actual:", solution.isSameTree(tree3, tree4))


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The isSameTree function checks if two binary trees are identical.
# It uses a depth-first search (DFS) approach to traverse both trees simultaneously.
# If the structure and node values of both trees match, it returns True; otherwise, it returns False.
