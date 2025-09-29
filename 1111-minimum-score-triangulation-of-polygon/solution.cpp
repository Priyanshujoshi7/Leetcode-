#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        // dp[i][j] = minimum score to triangulate polygon from vertex i to vertex j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill DP for increasing interval lengths
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try all possible k as the third vertex of triangle (i,k,j)
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][n-1]; // triangulate full polygon
    }
};

