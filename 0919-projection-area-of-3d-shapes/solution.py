class Solution:
    def projectionArea(self, grid: list[list[int]]) -> int:
        n = len(grid)
        xy_area = 0
        yz_area = 0
        zx_area = 0
        
        # Calculate xy_area (top) and yz_area (row maxes)
        for i in range(n):
            row_max = 0
            for j in range(n):
                if grid[i][j] > 0:
                    xy_area += 1
                if grid[i][j] > row_max:
                    row_max = grid[i][j]
            yz_area += row_max
            
        # Calculate zx_area (column maxes)
        for j in range(n):
            col_max = 0
            for i in range(n):
                if grid[i][j] > col_max:
                    col_max = grid[i][j]
            zx_area += col_max
            
        return xy_area + yz_area + zx_area

