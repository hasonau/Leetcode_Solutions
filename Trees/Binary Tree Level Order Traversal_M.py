from collections import deque
from typing import Optional,List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        my_queue = deque()
        # In case there is no node, the queue will be empty and the result will be []
        if root:
            my_queue.appendleft(root)

        result = []
        while my_queue:
            # Initialize a new list for the current level
            level = []
            # Get the count of nodes at the current level
            count = len(my_queue)
            for _ in range(count):
                # Pop the node from the right
                node = my_queue.pop()
                # Append the node's value to the current level list
                level.append(node.val)
                # Add left and right children to the queue
                if node.left:
                    my_queue.appendleft(node.left)
                if node.right:
                    my_queue.appendleft(node.right)
            # Append the current level list to the result list
            result.append(level)
        return result


# Main function to test the levelOrder function
def main():
    # Create a test case tree
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    solution = Solution()

    # Get the level order traversal of the tree
    result = solution.levelOrder(root)
    print("Level order traversal of the tree is:", result)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The levelOrder function performs a level-order traversal of a binary tree using a queue.
# It uses a deque to efficiently pop nodes from the right and append children to the left.
# For each level, it collects the node values in a list and appends it to the result list.
