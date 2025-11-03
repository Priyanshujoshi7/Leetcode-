class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = 0;  // To store the total time cost of removing balloons

        // Start from the second balloon
        for (int i = 1; i < n; i++) {
            int maxi = 0;  // To track the max removal time in a group of same-colored balloons

            // Traverse through consecutive balloons of the same color
            while (i < n && colors[i] == colors[i - 1]) {
                // Add the previous balloon’s time (as we might remove it)
                sum += neededTime[i - 1];
                // Track the highest time (the one we should keep)
                maxi = max(maxi, neededTime[i - 1]);
                ++i;  // Move forward
            }

            // Add the last balloon in this group
            sum += neededTime[i - 1];
            maxi = max(maxi, neededTime[i - 1]);  // Update max time for this group

            // Subtract the highest removal time (we keep that balloon)
            if (maxi != 0)
                sum -= maxi;
        }

        return sum;  // Minimum total time to remove balloons
    }
};

