class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Declare a 2D vector to store the Pascal's Triangle
        vector<vector<int>> result;
        
        // Handle the edge case where numRows is 0
        if (numRows == 0) return {};  // Return an empty vector if no rows are required
        
        // Handle the edge case where numRows is 1
        if (numRows == 1) return {{1}};  // Return a triangle with a single row: [1]

        // Iterate through each row from 0 to numRows - 1
        for (int i = 0; i < numRows; ++i) {
            // Create a new row of size (i + 1) with all elements initialized to 1
            result.push_back(vector<int>(i + 1, 1));
        }

        // Start calculating the inner elements of Pascal's Triangle from the 3rd row (index 2)
        for (int i = 2; i < numRows; ++i) {
            // Iterate through each inner element of the row (excluding the first and last elements)
            for (int j = 1; j < result[i].size() - 1; ++j) {
                // Calculate the value of the current element as the sum of the two elements
                // directly above it in the previous row
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        // Return the fully constructed Pascal's Triangle
        return result;
    }
};
