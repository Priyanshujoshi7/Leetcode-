class Solution {
public:
    long long maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        // We'll store the maximum energy we can get starting from each magician
        vector<long long> dp(n, 0);

        // Start from the end since after taking energy from i,
        // you can only go to i + k
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = energy[i];

            // If there's a valid jump to i + k, add that energy too
            if (i + k < n) {
                dp[i] += dp[i + k];
            }
        }

        // The answer is the maximum energy we can collect
        // starting from any magician
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

