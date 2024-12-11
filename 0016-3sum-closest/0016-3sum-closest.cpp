class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int closestSum = INT_MAX; // To track the closest sum
        int minDiff = INT_MAX;    // To track the minimum difference
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                
                // Update closest sum and minimum difference
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
                
                // Move pointers based on comparison with target
                if (sum > target) {
                    k--; // Reduce the sum
                } else if (sum < target) {
                    j++; // Increase the sum
                } else {
                    // Exact match found
                    return sum;
                }
            }
        }
        
        return closestSum;
    }
};
