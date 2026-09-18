class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        # Initialize the triangle with the first row
        triangle = []
        
        for i in range(numRows):
            # A row of size (i + 1) filled with 1s
            row = [1] * (i + 1)
            
            # Update the inner elements of the row
            # (elements between the first and last index)
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
                
            triangle.append(row)
            
        return triangle
