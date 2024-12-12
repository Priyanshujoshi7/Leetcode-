class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // No jumps needed if there's only one element
        
        int jumps = 0;
        int current_end = 0;
        int far = 0;

        for (int i = 0; i < n - 1; ++i) {
            far = max(far, i + nums[i]); // Update the farthest point reachable
            
            if (i == current_end) {
                // Need to make a jump
                jumps++;
                current_end = far;
                
                if (current_end >= n - 1) break; // If we can reach the end, stop early
            }
        }

        return jumps;
    }
};
