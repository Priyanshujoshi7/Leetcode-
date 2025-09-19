#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

class Spreadsheet {
private:
    int rows, cols;                     // Number of rows and columns in the spreadsheet
    vector<vector<int>> grid;           // 2D grid to store cell values

    // Helper function: parse a cell reference string (e.g., "A1") into (row, col) indices
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';        // Convert column letter to index: 'A' -> 0, 'B' -> 1, ...
        int row = stoi(cell.substr(1)) - 1; // Convert row number (string) to int and make it 0-indexed
        return {row, col};              // Return row and column indices
    }

    // Helper function: get value of a token
    // If token is a cell reference (like "A1"), return its stored value
    // If token is a number (like "5"), return it as integer
    int getTokenValue(const string &token) {
        if (isalpha(token[0])) {        // Check if token starts with a letter → it's a cell
            auto [r, c] = parseCell(token); // Parse cell reference into row and col
            return grid[r][c];          // Return value stored at that cell
        }
        return stoi(token);             // Otherwise, it's a number → convert to int
    }

public:
    // Constructor: initialize spreadsheet with given number of rows and 26 columns
    Spreadsheet(int r) {
        rows = r;                       // Save number of rows
        cols = 26;                      // Spreadsheet always has 26 columns ('A' to 'Z')
        grid.assign(rows, vector<int>(cols, 0)); // Initialize all cells to 0
    }
    
    // Set a cell to a given value
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);  // Convert cell reference to row and column
        grid[r][c] = value;             // Store value at that cell
    }
    
    // Reset a cell value to 0
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);  // Convert cell reference to row and column
        grid[r][c] = 0;                 // Reset value at that cell
    }
    
    // Evaluate a formula of the form "=X+Y"
    int getValue(string formula) {
        formula = formula.substr(1);    // Remove '=' at the beginning of formula
        int plusPos = formula.find('+');// Find position of '+' operator
        string left = formula.substr(0, plusPos);    // Extract left token (X)
        string right = formula.substr(plusPos + 1);  // Extract right token (Y)

        int val1 = getTokenValue(left); // Get value of left token (cell or number)
        int val2 = getTokenValue(right);// Get value of right token (cell or number)
        return val1 + val2;             // Return sum
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);   // Create spreadsheet with given rows
 * obj->setCell(cell,value);                   // Set value in a cell
 * obj->resetCell(cell);                       // Reset cell to 0
 * int param_3 = obj->getValue(formula);       // Evaluate a formula and get result
 */

