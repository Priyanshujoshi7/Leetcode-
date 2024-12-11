class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 1;
        while (set.find(ans) != set.end()) {
            ans++;
        }
        return ans;
    }
};