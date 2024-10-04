#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> sum_count;
        int sum = 0;
        int result = 0;
        sum_count[0] = 1; // To handle the case where the sum is exactly equal to k

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Check if there is a subarray that sums to k
            result += sum_count[sum - k];

            // Update the frequency of the current sum in the map
            sum_count[sum]++;
        }

        return result;
    }
};
