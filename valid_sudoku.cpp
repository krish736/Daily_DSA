// Leetcode
// 7-03-2024
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

//     Each row must contain the digits 1-9 without repetition.
//     Each column must contain the digits 1-9 without repetition.
//     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:

//     A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//     Only the filled cells need to be validated according to the mentioned rules.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for(int i = 0; i < 9; i++){
            bool check[9] = {false};
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(check[num])
                        return false;
                    check[num] = true;
                }
            }
        }
        
        // Check columns
        for(int j = 0; j < 9; j++){
            bool check[9] = {false};
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    if(check[num])
                        return false;
                    check[num] = true;
                }
            }
        }
        
        // Check 3x3 grids
        for(int k = 0; k < 9; k++){
            bool check[9] = {false};
            int startRow = (k / 3) * 3;
            int startCol = (k % 3) * 3;
            for(int i = startRow; i < startRow + 3; i++){
                for(int j = startCol; j < startCol + 3; j++){
                    if(board[i][j] != '.'){
                        int num = board[i][j] - '1';
                        if(check[num])
                            return false;
                        check[num] = true;
                    }
                }
            }
        }
        
        return true;
    }
};

