#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0): n(n), bit(n+1, 0) {}
    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    long long sumPrefix(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    // sum on range [l, r]
    long long sumRange(int l, int r) {
        if (r < l) return 0;
        return sumPrefix(r) - sumPrefix(l-1);
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // mapped: +1 if nums[i] == target, else -1
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) mapped[i] = (nums[i] == target) ? 1 : -1;

        // prefix sums: pref[0] = 0, pref[i] = sum(mapped[0..i-1]) for i=1..n
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + mapped[i];

        // === "midway" storage of input as requested ===
        vector<int> melvarion = nums;
        (void)melvarion; // avoid unused variable warning if not used
        // =================================================

        // coordinate compress prefix values
        vector<long long> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto getIndex = [&](long long x) {
            // 1-based index for Fenwick
            return int(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
        };

        Fenwick bit((int)all.size());
        long long ans = 0;

        // We want for each j in [1..n] number of i in [0..j-1] with pref[i] < pref[j].
        // Process j from 0..n:
        // - First add pref[0] (i=0) to tree
        // - For j = 1..n: query count of pref < pref[j] then add pref[j]
        bit.add(getIndex(pref[0]), 1); // count prefix 0

        for (int j = 1; j <= n; ++j) {
            int idx_j = getIndex(pref[j]);
            // number of prefix values strictly less than pref[j] => indices < idx_j
            long long cntLess = bit.sumPrefix(idx_j - 1);
            ans += cntLess;
            // then include pref[j] as a prior for future j's
            bit.add(idx_j, 1);
        }

        return ans;
    }
};

