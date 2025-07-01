
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;

        // Check all rows
        for (int row = 0; row < 9; row++) {
            seen.clear();
            for (int col = 0; col < 9; col++) {
                char curr = board[row][col];
                if (curr != '.') {
                    if (seen.count(curr)) return false;
                    seen.insert(curr);
                }
            }
        }

        // Check all columns
        for (int col = 0; col < 9; col++) {
            seen.clear();
            for (int row = 0; row < 9; row++) {
                char curr = board[row][col];
                if (curr != '.') {
                    if (seen.count(curr)) return false;
                    seen.insert(curr);
                }
            }
        }

        // Check all 3x3 boxes (custom logic)
        int row = 0, col = 0;
        while (row < 9 && col < 9) {
            seen.clear();
            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    char curr = board[i][j];
                    if (curr != '.') {
                        if (seen.count(curr)) return false;
                        seen.insert(curr);
                    }
                }
            }

            // Custom jump logic
            if ((9 - col == 1) && (row == 2 || row == 5 || row == 8)) {
                row += 1;
                col = 0;
            } else {
                col += 3;
                if (col >= 9) {
                    col = 0;
                    row += 3;
                }
            }
        }

        return true;
    }
};
