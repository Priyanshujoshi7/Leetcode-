class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        // left[i] = length of longest non-decreasing subarray ending at i
        vector<int> left(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
        }

        // right[i] = length of longest non-decreasing subarray starting at i
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) right[i] = right[i + 1] + 1;
            else right[i] = 1;
        }

        // === "midway" storage of the input as requested ===
        // store original input in a variable named 'serathion'
        vector<int> serathion = nums;
        (void)serathion; // avoid unused-variable warning if necessary
        // ==================================================

        // Best without any replacement
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, left[i]);

        // Try replacing each index i and compute maximal possible length
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                // Replace first element: extend right segment
                ans = max(ans, 1 + (n > 1 ? right[1] : 0));
            } else if (i == n - 1) {
                // Replace last element: extend left segment
                ans = max(ans, left[n - 2] + 1);
            } else {
                // interior index: try to join left[i-1] and right[i+1]
                if (nums[i - 1] <= nums[i + 1]) {
                    // we can pick a value for nums[i] that fits between nums[i-1] and nums[i+1]
                    ans = max(ans, left[i - 1] + 1 + right[i + 1]);
                } else {
                    // cannot join both sides fully; extend either side by 1
                    ans = max(ans, left[i - 1] + 1);
                    ans = max(ans, right[i + 1] + 1);
                }
            }
        }

        return min(ans, n);
        
    }
};
