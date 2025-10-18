class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Step 1: Sort the array so we can process elements in order
        sort(nums.begin(), nums.end());

        long long last = LLONG_MIN; // Keeps track of the last distinct number used
        int count = 0;              // Total count of distinct elements

        // Step 2: Iterate over each element
        for (int num : nums) {
            // Each element can be changed within the range [num - k, num + k]
            long long left = (long long)num - k;
            long long right = (long long)num + k;

            // Find the smallest possible distinct number > last
            long long candidate = max(left, last + 1);

            // If the candidate is within allowed range, we can use it
            if (candidate <= right) {
                count++;      // One more distinct element
                last = candidate;  // Update last used distinct number
            }
            // If candidate > right → skip (cannot make it distinct)
        }

        return count;
    }
};

