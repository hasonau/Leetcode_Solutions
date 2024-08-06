class TrieNode:
    def __init__(self):
        # Dictionary to hold child nodes
        self.children = {}
        # Boolean flag to indicate if a word ends at this node
        self.word = False


class WordDictionary:

    def __init__(self):
        # Initialize the WordDictionary with a root node and other helper variables
        self.root = TrieNode()
        # To keep track of the longest word length
        self.maximum = 0
        # Set to check if the exact word exists
        self.wordCheck = set()

    def addWord(self, word: str) -> None:
        # Start from the root node
        curr = self.root
        # Add word to the set for direct lookup
        self.wordCheck.add(word)
        # Update the maximum length of words in the dictionary
        self.maximum = max(len(word), self.maximum)
        # Insert the word into the Trie
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        # Mark the end of the word
        curr.word = True

    def search(self, word: str) -> bool:
        # Directly check if the exact word exists in the set
        if word in self.wordCheck:
            return True

        def dfs(j, root):
            curr = root
            # Iterate through the characters of the word starting from index j
            for i in range(j, len(word)):
                if word[i] == '.':
                    # Try all possible children nodes if '.' is encountered
                    for child in curr.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    # Check if the character exists in the current node's children
                    if word[i] not in curr.children:
                        return False
                    curr = curr.children[word[i]]
            return curr.word

        # Check if the word length is within the maximum length
        if self.maximum < len(word):
            return False
        else:
            return dfs(0, self.root)


# Main function to test the WordDictionary
def main():
    wd = WordDictionary()

    # Add words to the dictionary
    wd.addWord("bad")
    wd.addWord("dad")
    wd.addWord("mad")

    # Test the search function
    print("Search 'pad':", wd.search("pad"))  # Expected: False
    print("Search 'bad':", wd.search("bad"))  # Expected: True
    print("Search '.ad':", wd.search(".ad"))  # Expected: True
    print("Search 'b..':", wd.search("b.."))  # Expected: True


if __name__ == "__main__":
    main()

# Comments on 2024-08-06
# The WordDictionary class implements a data structure that supports adding words and searching for them, including support for wildcards.
# - `addWord(word)` method inserts a word into the dictionary and updates the maximum length.
# - `search(word)` method searches for a word or pattern (with '.' as a wildcard) in the dictionary using depth-first search.
# - The `wordCheck` set allows for efficient exact word lookup, and the `dfs` function handles the wildcard search.
# The main function demonstrates adding words to the dictionary and searching with different patterns.
