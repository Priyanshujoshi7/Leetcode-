#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    int rows, cols;
    vector<vector<int>> grid;

    // Parse "A1" -> (row, col)
    pair<int,int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; // 1-indexed to 0-indexed
        return {row, col};
    }

    // Return value if token is cell ref or integer
    int getTokenValue(const string &token) {
        if (isalpha(token[0])) {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
        return stoi(token);
    }

public:
    Spreadsheet(int r) {
        rows = r;
        cols = 26;
        grid.assign(rows, vector<int>(cols, 0));
    }
    
    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getTokenValue(left);
        int val2 = getTokenValue(right);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

