#include <iostream>
using namespace std;

void printSudoku(int sudoku[][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9;j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit) {
    // vertical 
    for(int i=0; i<=8; i++) {
        if (sudoku[i][col] == digit) {
            return false;
        }
    }
    // column 
    for(int j=0; j<=8; j++) {
        if (sudoku[row][j] == digit) {
            return false;
        }
    }
    // checking in grid 3x3
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i<=startRow+2; i++){
        for(int j=startCol; j<=startCol+2; j++) {
            if(sudoku[i][j] == digit) {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if (row == 9){
        printSudoku(sudoku);
        return true;
    }

    int nextRow = row;
    int nextCol = col+1;
    if(col+1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for (int digit=1; digit<=9; digit++) {
        if (isSafe(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    
    return false;
}


int main(){
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};

    sudokuSolver(sudoku, 0, 0);
    return 0;
    
}


// gfg

class Solution {
  public:
    // check if placing 'digit' at (row, col) is valid
    bool isSafe(vector<vector<int>> &mat, int row, int col, int digit) {
        // check column
        for (int i = 0; i < 9; i++) 
            if (mat[i][col] == digit) return false;
        
        // check row
        for (int j = 0; j < 9; j++) 
            if (mat[row][j] == digit) return false;
        
        // check 3x3 subgrid
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (mat[i][j] == digit) return false;
            }
        }
        return true;
    }
    
    // backtracking solver
    bool sudokuSolver(vector<vector<int>> &mat, int row, int col) {
        // solved all rows
        if (row == 9) return true;  
        
        // move to next cell
        int nextRow = row, nextCol = col + 1;
        if (col == 8) { 
            nextRow = row + 1; 
            nextCol = 0; 
        }
        
        // skip prefilled cell
        if (mat[row][col] != 0) 
            return sudokuSolver(mat, nextRow, nextCol);
        
        // try placing digits 1–9
        for (int digit = 1; digit <= 9; digit++) {
            if (isSafe(mat, row, col, digit)) {
                mat[row][col] = digit;   // place
                if (sudokuSolver(mat, nextRow, nextCol)) return true;
                mat[row][col] = 0;       // backtrack
            }
        }
        return false; // no valid digit
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        sudokuSolver(mat, 0, 0);
    }
};
