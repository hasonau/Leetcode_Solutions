# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        goodCount = [0]

        def dfs(root, maximum):
            if not root:
                return
            if maximum <= root.val:
                goodCount[0] += 1
            maximum = max(maximum, root.val)

            dfs(root.left, maximum)
            dfs(root.right, maximum)
            return

        dfs(root, float("-infinity"))
        return goodCount[0]


# Main function to test the goodNodes function
def main():
    # Create a test case tree
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.left = TreeNode(3)
    root.right.left = TreeNode(1)
    root.right.right = TreeNode(5)

    solution = Solution()

    # Get the count of good nodes in the tree
    count = solution.goodNodes(root)
    print("Number of good nodes in the tree:", count)


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The goodNodes function counts the number of good nodes in a binary tree.
# A node is considered good if it is the largest value encountered along the path from the root to that node.
# The function uses a depth-first search (DFS) to traverse the tree and keep track of the maximum value encountered so far.
# If the current node's value is greater than or equal to the maximum value, it increments the good node count.
