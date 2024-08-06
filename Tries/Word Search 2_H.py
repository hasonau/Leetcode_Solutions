# THis won't get accepted at leetcode,beacuse it takes hell lot of time.
from typing import List


class Solution:
    def __init__(self):
        self.my_set = set()

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        rows = len(board)
        columns = len(board[0])
        res = []

        def dfs(i, j, k):
            # If all characters are found, return True
            if k == len(word):
                return True

            # Explore the four possible directions
            if i - 1 >= 0 and board[i - 1][j] == word[k] and (i - 1, j) not in self.my_set:
                self.my_set.add((i - 1, j))
                if dfs(i - 1, j, k + 1):
                    return True
                self.my_set.remove((i - 1, j))

            if i + 1 < rows and board[i + 1][j] == word[k] and (i + 1, j) not in self.my_set:
                self.my_set.add((i + 1, j))
                if dfs(i + 1, j, k + 1):
                    return True
                self.my_set.remove((i + 1, j))

            if j - 1 >= 0 and board[i][j - 1] == word[k] and (i, j - 1) not in self.my_set:
                self.my_set.add((i, j - 1))
                if dfs(i, j - 1, k + 1):
                    return True
                self.my_set.remove((i, j - 1))

            if j + 1 < columns and board[i][j + 1] == word[k] and (i, j + 1) not in self.my_set:
                self.my_set.add((i, j + 1))
                if dfs(i, j + 1, k + 1):
                    return True
                self.my_set.remove((i, j + 1))

            return False

        for word in words:
            found = False
            for i in range(rows):
                for j in range(columns):
                    self.my_set.add((i, j))
                    if board[i][j] == word[0] and dfs(i, j, 1):
                        res.append(word)
                        found = True
                        self.my_set.clear()
                        break
                    self.my_set.clear()
                if found:
                    break

        return res


# Main function to test the Solution class
if __name__ == "__main__":
    # Test case
    board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
    words =["oath","pea","eat","rain"]
    solution = Solution()
    result = solution.findWords(board, words)

    # Expected output: ['oath', 'eat']
    print("Found words:", result)
