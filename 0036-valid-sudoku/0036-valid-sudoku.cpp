class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen;

        for(int col = 0 ; col < 9 ; col++){
            for(int row = 0 ; row < 9; row++){

                if(board[row][col] == '.') continue;
                
                if(seen.contains(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
            seen.clear();
        }

        
        for(int col = 0 ; col < 9 ; col++){
            for(int row = 0 ; row < 9; row++){
                
                if(board[col][row] == '.') continue;

                if(seen.contains(board[col][row])) return false;
                seen.insert(board[col][row]);
            }
            seen.clear();
        }

        for(int col = 0 ;col < 9 ; col+=3){
            for(int row = 0 ; row < 9 ; row+=3){
                
                int row_limit = row + 3;
                int col_limit = col + 3;


                for(int i = row ; i < row_limit ; i++){
                    for(int j = col ; j < col_limit; j++){

                        if(board[i][j] == '.') continue;

                        if(seen.contains(board[i][j])) return false;
                        seen.insert(board[i][j]);
                    }
                }
                // clearence should be done after the whole 3 by 3 box,
                // i was doing it inside,the last code i submitted
                seen.clear();

            }
        }

        return true;
        
    }
};