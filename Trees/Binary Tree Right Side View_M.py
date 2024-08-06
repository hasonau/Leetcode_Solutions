from collections import deque
from typing import Optional,List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if not root:
            return result

        q = deque()
        q.append(root)

        while q:
            result.append(q[-1].val)
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return result


# Main function to test the rightSideView function
def main():
    # Create a test case tree
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)

    solution = Solution()

    # Get the right side view of the tree
    view = solution.rightSideView(root)
    print("Right side view of the tree:", view)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The rightSideView function returns the right side view of a binary tree.
# It performs a breadth-first search (BFS) and collects the rightmost node's value at each level.
# It uses a deque to efficiently handle the queue operations during BFS.
# The function only adds the last node at each level to the result list, representing the right side view.
