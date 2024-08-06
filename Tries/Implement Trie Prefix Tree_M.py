class TrieNode:
    def __init__(self):
        # Dictionary to hold children nodes
        self.children = {}
        # Boolean flag to indicate if a word ends at this node
        self.word = False


class Trie:

    def __init__(self):
        # Initialize the Trie with a root node
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        # Start from the root node
        curr = self.root
        for c in word:
            # If the character is not already a child, add it
            if c not in curr.children:
                curr.children[c] = TrieNode()
            # Move to the child node
            curr = curr.children[c]
        # Mark the end of the word
        curr.word = True

    def search(self, word: str) -> bool:
        # Start from the root node
        curr = self.root
        for c in word:
            # If the character is not found, return False
            if c not in curr.children:
                return False
            # Move to the child node
            curr = curr.children[c]
        # Return True if the end of the word is reached
        return curr.word

    def startsWith(self, prefix: str) -> bool:
        # Start from the root node
        curr = self.root
        for c in prefix:
            # If the character is not found, return False
            if c not in curr.children:
                return False
            # Move to the child node
            curr = curr.children[c]
        # Return True if the prefix exists
        return True


# Main function to test the Trie
def main():
    trie = Trie()

    # Insert words into the Trie
    trie.insert("apple")
    trie.insert("app")

    # Test search function
    print("Search 'apple':", trie.search("apple"))  # Expected: True
    print("Search 'app':", trie.search("app"))  # Expected: True
    print("Search 'appl':", trie.search("appl"))  # Expected: False

    # Test startsWith function
    print("Starts with 'app':", trie.startsWith("app"))  # Expected: True
    print("Starts with 'apl':", trie.startsWith("apl"))  # Expected: False


if __name__ == "__main__":
    main()

# Commented on 2024-08-06
# The Trie class provides a data structure for efficient word storage and retrieval.
# - `insert` method adds a word to the Trie.
# - `search` method checks if a word exists in the Trie.
# - `startsWith` method checks if there is any word in the Trie that starts with a given prefix.
# The main function demonstrates inserting words into the Trie and testing the `search` and `startsWith` methods.
