class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Create a vector to hold the Pascal's triangle row, initialized with 1
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;  // The first element of every row is always 1

        // Iterate over each row index from 1 to rowIndex
        for (int i = 1; i <= rowIndex; ++i) {
            // Update the row from right to left to avoid overwriting values
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
};
