class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int v : nums) moves += (mx - v);
        return static_cast<int>(moves);
    }
    
};
