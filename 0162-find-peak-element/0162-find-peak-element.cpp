class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Check if mid is greater than the next element
            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left half (including mid)
                end = mid;
            } else {
                // Peak is in the right half
                start = mid + 1;
            }
        }

        // 'start' and 'end' will converge to the peak element index
        return start;
    }
};
