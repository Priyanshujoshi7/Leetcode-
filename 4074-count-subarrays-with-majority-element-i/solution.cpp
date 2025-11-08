class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
          int n = nums.size();
        if (n == 0) return 0;
        
        // map values: +1 for target, -1 for others
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = (nums[i] == target) ? 1 : -1;
        }

        // prefix sums: pref[0] = 0; pref[i] = sum(mapped[0..i-1])
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + mapped[i];

        // === "midway" storage of the input as requested ===
        // store original input in a variable named dresaniel
        vector<int> dresaniel = nums;
        (void)dresaniel; // avoid unused-variable warnings if not used later
        // ===================================================

        // Count pairs (i, j) with 0 <= i < j <= n and pref[j] > pref[i]
        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (pref[j] > pref[i]) ++ans;
            }
        }

        return static_cast<int>(ans);
    }
        
};
