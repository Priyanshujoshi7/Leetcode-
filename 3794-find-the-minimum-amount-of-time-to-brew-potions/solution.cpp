class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        
        // 'done' array stores the cumulative time or effort for each skill level
        vector<long long> done(n + 1, 0);

        // Iterate through each mana value
        for (int j = 0; j < m; ++j) {
            
            // Forward pass: accumulate total time using current mana and skill
            for (int i = 0; i < n; ++i) {
                // For each skill, take the maximum progress from previous step
                // and add time = mana[j] * skill[i]
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];
            }

            // Backward pass: adjust values to maintain decreasing pattern
            // (likely to rebalance or back-propagate minimum possible time)
            for (int i = n - 1; i > 0; --i) {
                done[i] = done[i + 1] - 1LL * mana[j] * skill[i];
            }
        }

        // Final minimum time after processing all skills and mana
        return done[n];
    }
};

