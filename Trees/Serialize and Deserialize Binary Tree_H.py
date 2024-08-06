import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        # DOING A BFS and on removal from deque, adding values to string, instead of using N for null, we used 1001
        # because it is mentioned in the problem that the node value range is between 1000 and -1001

        # if root is empty, return empty string
        if not root:
            return ""

        q = collections.deque()
        q.append(root)
        result = ""

        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.val == 1001:
                    result += "1001#"
                    continue
                else:
                    q.append(node.left) if node.left else q.append(TreeNode(1001))
                    q.append(node.right) if node.right else q.append(TreeNode(1001))
                    result += str(node.val) + "#"
        return result

    def deserialize(self, data):
        if not data:
            return None

        left = 0
        while data[left] != '#':
            left += 1
        q = collections.deque()

        # first node is found and sent to deque in order to start BFS traversal and on removal
        # appending values accordingly
        root = TreeNode(int(data[0:left]))
        q.append(root)
        left = right = left + 1

        while q:
            for j in range(len(q)):
                node = q.popleft()
                count = 0
                while count < 2:
                    if data[right] == '#':
                        val = int(data[left:right])
                        if count == 0:
                            node.left = TreeNode(val) if val != 1001 else None
                            if node.left: q.append(node.left)
                        else:
                            node.right = TreeNode(val) if val != 1001 else None
                            if node.right: q.append(node.right)
                        count += 1
                        left = right + 1
                    right += 1

        return root


# Main function to test the Codec class
def main():
    # Create a test case tree
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)

    codec = Codec()

    # Serialize the tree
    serialized = codec.serialize(root)
    print("Serialized tree:", serialized)

    # Deserialize the tree
    deserialized = codec.deserialize(serialized)

    # Check the structure of the deserialized tree
    def level_order_traversal(root):
        if not root:
            return []
        result = []
        q = collections.deque([root])
        while q:
            node = q.popleft()
            result.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return result

    print("Deserialized tree (level order):", level_order_traversal(deserialized))


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Codec class provides methods to serialize and deserialize a binary tree.
# The serialize method performs a breadth-first search (BFS) to convert the tree to a string representation,
# using 1001 to represent null nodes.
# The deserialize method converts the string back to a binary tree using BFS.
# The main function creates a test case, serializes the tree, deserializes it, and verifies the structure with a level order traversal.
