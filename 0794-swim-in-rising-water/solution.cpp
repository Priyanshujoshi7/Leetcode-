#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Directions for moving up, down, left, right
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // Min-heap: stores {time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Visited matrix to avoid revisiting cells
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start from (0,0) with initial time equal to elevation of starting cell
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int time = curr[0];
            int x = curr[1];
            int y = curr[2];
            
            // If reached destination (bottom-right), return current time
            if (x == n - 1 && y == n - 1)
                return time;
            
            // Skip if already visited
            if (visited[x][y])
                continue;
            visited[x][y] = true;
            
            // Explore all 4 possible directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                // Check boundaries and if not visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    // Water level needed to reach this cell
                    int nextTime = max(time, grid[nx][ny]);
                    pq.push({nextTime, nx, ny});
                }
            }
        }
        
        return -1; // Should never reach here
    }
};

