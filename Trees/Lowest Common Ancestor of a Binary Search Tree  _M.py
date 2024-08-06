# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # If both p and q are greater than root, LCA must be in the right subtree
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        # If both p and q are less than root, LCA must be in the left subtree
        elif p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        # If root is either p or q, or p and q are on different sides, root is the LCA
        else:
            return root


# Main function to test the lowestCommonAncestor function
def main():
    # Create a test case tree
    root = TreeNode(6)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.left.right.left = TreeNode(3)
    root.left.right.right = TreeNode(5)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)

    # Define nodes p and q
    p = root.left  # Node with value 2
    q = root.left.right  # Node with value 4

    solution = Solution()

    # Find the LCA of nodes p and q
    lca = solution.lowestCommonAncestor(root, p, q)
    print("LCA of nodes", p.val, "and", q.val, "is:", lca.val)

    # Define another pair of nodes p and q
    p = root.left  # Node with value 2
    q = root.right  # Node with value 8

    # Find the LCA of nodes p and q
    lca = solution.lowestCommonAncestor(root, p, q)
    print("LCA of nodes", p.val, "and", q.val, "is:", lca.val)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The lowestCommonAncestor function finds the lowest common ancestor (LCA) of two nodes in a binary search tree.
# If both nodes are on the same side (left or right) of the root, it recursively searches in that subtree.
# If the root is either of the nodes or the nodes are on different sides, the root is the LCA.
