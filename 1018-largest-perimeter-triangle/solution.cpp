#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Step 1: Sort in descending order (largest sides first)
        sort(nums.begin(), nums.end(), greater<int>());

        // Step 2: Iterate and check each triplet
        for (int i = 0; i + 2 < nums.size(); i++) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            
            // Triangle inequality: sum of smaller two > largest
            if (b + c > a) {
                return a + b + c; // Found largest valid perimeter
            }
        }

        // Step 3: If no valid triangle found
        return 0;
    }
};

