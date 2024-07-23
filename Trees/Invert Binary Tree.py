from collections import deque
from typing import List,Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        root.right, root.left = root.left, root.right
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root

def level_order_traversal(root: TreeNode) -> list:
    if not root:
        return []
    result = []
    queue = deque([root])
    while queue:
        node = queue.popleft()
        result.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    return result

# Example tree creation
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)
root.right.left = TreeNode(6)
root.right.right = TreeNode(9)

solution = Solution()
inverted_root = solution.invertTree(root)

# Print the level-order traversal of the inverted tree
print(level_order_traversal(inverted_root))

def main():
    # Create the binary tree
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(7)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(9)

    # Invert the binary tree
    solution = Solution()
    inverted_root = solution.invertTree(root)

    # Get and print the level-order traversal of the inverted tree
    print(level_order_traversal(inverted_root))

if __name__ == "__main__":
    main()
