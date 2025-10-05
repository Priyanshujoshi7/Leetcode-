#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        // visited matrices for Pacific and Atlantic
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // directions for exploring neighbors (up, down, left, right)
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // DFS function
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& ocean) {
            ocean[r][c] = true; // mark visited
            for(auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                // check bounds
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                // only move to neighbor if not visited and height is >= current (reverse flow)
                if(!ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, ocean);
                }
            }
        };
        
        // Run DFS from Pacific border (top row + left column)
        for(int c = 0; c < n; c++) dfs(0, c, pacific);   // top row
        for(int r = 0; r < m; r++) dfs(r, 0, pacific);   // left column
        
        // Run DFS from Atlantic border (bottom row + right column)
        for(int c = 0; c < n; c++) dfs(m-1, c, atlantic); // bottom row
        for(int r = 0; r < m; r++) dfs(r, n-1, atlantic); // right column
        
        // Collect results: cells reachable from both oceans
        vector<vector<int>> result;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};

