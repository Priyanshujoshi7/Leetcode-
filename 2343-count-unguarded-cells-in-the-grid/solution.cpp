class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // grid values:
        // 0 = empty (unoccupied & unguarded)
        // 1 = guard
        // 2 = wall
        // 3 = guarded (seen by >= 1 guard)
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // place guards (1)
        for (const auto &g : guards) {
            int r = g[0], c = g[1];
            if (r >= 0 && r < m && c >= 0 && c < n) grid[r][c] = 1;
        }
        // place walls (2)
        for (const auto &w : walls) {
            int r = w[0], c = w[1];
            if (r >= 0 && r < m && c >= 0 && c < n) grid[r][c] = 2;
        }
        
        // helper to scan from (r,c) in direction (dr,dc) marking guarded cells
        auto scan_direction = [&](int r, int c, int dr, int dc) {
            int cr = r + dr;
            int cc = c + dc;
            while (cr >= 0 && cr < m && cc >= 0 && cc < n) {
                // stop when encountering wall or another guard
                if (grid[cr][cc] == 2 || grid[cr][cc] == 1) break;
                // mark empty cells as guarded
                if (grid[cr][cc] == 0) grid[cr][cc] = 3;
                cr += dr;
                cc += dc;
            }
        };
        
        // for each guard, scan up/down/left/right
        for (const auto &g : guards) {
            int r = g[0], c = g[1];
            // ensure guard coordinates are valid (defensive)
            if (r < 0 || r >= m || c < 0 || c >= n) continue;
            scan_direction(r, c, -1, 0); // up
            scan_direction(r, c, 1, 0);  // down
            scan_direction(r, c, 0, -1); // left
            scan_direction(r, c, 0, 1);  // right
        }
        
        // count unoccupied & unguarded cells (value 0)
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) ++count;
            }
        }
        return count;
    }
};

