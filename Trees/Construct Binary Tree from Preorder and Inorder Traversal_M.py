# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import Optional,List
from collections import deque
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        if len(preorder) == len(inorder) == 1:
            return TreeNode(preorder[0])

        root = TreeNode(preorder[0])
        # Find the index where the root value (preorder[0]) is located in the inorder list
        slice_point = 0
        for i in range(len(inorder)):
            if preorder[0] == inorder[i]:
                slice_point = i
                break

        # Recursively build the left and right subtrees
        root.left = self.buildTree(preorder[1:slice_point + 1], inorder[:slice_point])
        root.right = self.buildTree(preorder[slice_point + 1:], inorder[slice_point + 1:])

        return root


# Main function to test the buildTree function
def main():
    # Create test case data
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]

    solution = Solution()

    # Build the binary tree from the test case data
    root = solution.buildTree(preorder, inorder)

    # A function to print the tree in level order for verification
    def printLevelOrder(root):
        if not root:
            return "Tree is empty"

        result = []
        q = deque([root])

        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                if node:
                    level.append(node.val)
                    q.append(node.left)
                    q.append(node.right)
                else:
                    level.append(None)
            if any(x is not None for x in level):  # Skip printing empty levels
                result.append(level)

        return result

    # Print the built tree in level order
    print("Level Order Traversal of the Built Tree:", printLevelOrder(root))


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Solution class provides a method to build a binary tree from preorder and inorder traversal lists.
# The buildTree method recursively constructs the tree by finding the root from preorder, then partitioning
# the inorder list into left and right subtrees.
# The main function creates a sample binary tree using predefined preorder and inorder lists, then prints
# the level order traversal of the constructed tree to verify correctness.
