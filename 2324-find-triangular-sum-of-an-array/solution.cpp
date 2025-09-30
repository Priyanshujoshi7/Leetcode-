#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Keep reducing the array until only one element remains
        while (nums.size() > 1) {
            vector<int> newNums(nums.size() - 1);
            for (int i = 0; i < (int)nums.size() - 1; i++) {
                // Each new element = sum of two adjacent elements mod 10
                newNums[i] = (nums[i] + nums[i+1]) % 10;
            }
            nums = newNums; // Replace with reduced array
        }
        return nums[0]; // Final single element is the answer
    }
};

