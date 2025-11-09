// class Solution {
// public:
//     bool isSafe(vector<vector<char>>& board, int row, int col, char val) {
        
//         for (int i = 0; i < 9; i++) {
//             if (i != row && board[i][col] == val) // check column
//                 return false;
//             if (i != col && board[row][i] == val) // check row
//                 return false;
//         }

//         int startRow = (row / 3) * 3;
//         int startCol = (col / 3) * 3;

//         for (int i = startRow; i < startRow + 3; i++) {
//             for (int j = startCol; j < startCol + 3; j++) {
//                 if ((i != row || j != col) && board[i][j] == val)
//                     return false;
//             }
//         }

//         return true;
//     }

//     bool isValidSudoku(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] != '.') {
//                     if (!isSafe(board, i, j, board[i][j])) {
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };