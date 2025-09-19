#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    // 2D grid to store values of cells
    // grid[row][col], where col is 0..25 ('A'..'Z'), row is 0..rows-1
    vector<vector<int>> grid; 
    
    // Helper: Convert a cell reference (like "B10") to (row, col) indices
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';          // first char gives column (A=0, B=1, ...)
        int row = stoi(cell.substr(1)) - 1; // rest is row number, convert to 0-based
        return {row, col};
    }
    
    // Helper: Return the stored value of a cell reference
    int getCellValue(const string &cell) {
        auto [r, c] = parseCell(cell);
        return grid[r][c]; // return the integer stored in that cell
    }
    
    // Helper: Parse an operand in a formula
    // Operand can be either:
    //   - a number (e.g., "15")
    //   - a cell reference (e.g., "A1")
    int parseOperand(const string &s) {
        if (isdigit(s[0])) {
            // If it starts with a digit, it's a number → convert to int
            return stoi(s);
        } else {
            // Otherwise, it's a cell reference → lookup value in grid
            return getCellValue(s);
        }
    }

public:
    // Constructor: create a spreadsheet with given number of rows
    // All cells are initialized to 0
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0)); // 26 columns A-Z
    }
    
    // Set the given cell to a value
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    // Reset the given cell to 0
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    // Evaluate a formula of form "=X+Y"
    // Both X and Y can be either numbers or cell references
    int getValue(string formula) {
        // Remove the leading '='
        formula = formula.substr(1);
        
        // Find position of '+' (since formula is always X+Y)
        size_t plusPos = formula.find('+');
        
        // Split into left and right operands
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        
        // Evaluate each operand
        int val1 = parseOperand(left);
        int val2 = parseOperand(right);
        
        // Return sum
        return val1 + val2;
    }
};


// 🔑 Step-by-Step Summary
// grid → stores all cell values (rows × 26 grid).

// parseCell → converts "B10" → (row=9, col=1).

// getCellValue → retrieves the stored value of a cell.

// parseOperand → detects if operand is a number or a cell reference, and returns its value.

// setCell → assign a given integer to a cell.

// resetCell → reset cell back to 0.

// getValue →

// Remove =

// Split at +

// Parse both operands

// Return their sum.