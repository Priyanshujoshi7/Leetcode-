class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the numbers in increasing order
        sort(nums.begin(), nums.end());

        // Step 2: Initialize variables
        int leftPointer = 0;  
        long long totalSum = 0;  // Use long long to avoid overflow
        int maxFrequency = 0;

        // Step 3: Iterate through the array with the right pointer (rightPointer)
        for (int rightPointer = 0; rightPointer < nums.size(); ++rightPointer) {
            // Add the current number to the total sum
            totalSum += nums[rightPointer];

            // Step 4: Check if the current window is valid
            while (nums[rightPointer] * (long long)(rightPointer - leftPointer + 1) > totalSum + k) {
                totalSum -= nums[leftPointer];  // Shrink the window from the left
                leftPointer++;
            }

            // Step 5: Update the maximum frequency
            maxFrequency = max(maxFrequency, rightPointer - leftPointer + 1);
        }

        // Step 6: Return the result
        return maxFrequency;
    }
};
