
#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>>board) {
    int n = board.size();

    for (int i = 0;i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout <<"-------------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    // horizontal 
    for (int j = 0; j<n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    // vertical
    for (int j = 0; j<row; j++) {
        if (board[j][col] == 'Q') return false;
    }

    // diagonal left
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return 1;
    }

    int count = 0;  
    for(int j = 0; j<n; j++) {
        if (isSafe(board,row, j)) { 
            board[row][j] = 'Q';
           count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
    return count;
}


int main() {
    vector<vector<char>> board;
    int n = 4;

    for(int i = 0; i<n; i++) {
        vector<char>newRow;
        for (int j = 0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board, 0);
    cout << "count: " << count << endl;
    return 0;

}



/// gfg 

// User function Template for C++
class Solution {
  public:
    bool isSafe(vector<vector<char>>& board, int row, int col) {
        int n = board.size();
        //horizontal
        for(int j=0; j<n; j++) {
            if(board[row][j] == 'Q') return false;
        }
        
        //vertical
        for(int j=0; j<row; j++) {
            if (board[j][col] == 'Q') return false;
        }
        
        //diagonal left;
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        //diagonal right;
        for(int i=row, j=col; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void nQueens(vector<vector<char>>& board, int row, vector<vector<int>> &result) {
        int n = board.size();
        if (row == n) {
            vector<int> position;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if (board[i][j] == 'Q') {
                        position.push_back(j+1); // 1 based indexing
                    }
                }
            }
            result.push_back(position);
            return;
        }
        
        for(int j=0; j<n; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueens(board, row+1, result);
                board[row][j] = '.';
            }
        }
    }
    
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<char>> board;
        vector<vector<int>> result;
        
        for(int i=0; i<n; i++) {
            vector<char> newRow;
            
            for(int j=0; j<n; j++) {
                newRow.push_back('.');
            }
            board.push_back(newRow);
        }
        
        nQueens(board, 0, result);
        
        return result;
    }
};