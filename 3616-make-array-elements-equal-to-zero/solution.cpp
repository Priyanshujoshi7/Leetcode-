#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();                       // length of the array
        int answer = 0;                            // number of valid selections found

        // Try every index as the starting position
        for (int start = 0; start < n; ++start) {
            if (nums[start] != 0) continue;       // start must be at a 0, skip otherwise

            // Try both directions: -1 means left, +1 means right
            for (int initDir : {-1, +1}) {
                vector<int> arr = nums;           // make a copy to simulate on (preserve original)
                int pos = start;                  // current position
                int dir = initDir;                // current movement direction (-1 left, +1 right)

                // Simulate until pos goes outside [0, n-1]
                while (pos >= 0 && pos < n) {
                    if (arr[pos] == 0) {
                        // If current cell is zero, simply step in current direction
                        pos += dir;
                    } else {
                        // If current cell > 0, decrement it
                        arr[pos] -= 1;
                        // Reverse direction
                        dir = -dir;
                        // Take a step in the new direction
                        pos += dir;
                    }
                }

                // After simulation ends, check if all elements became zero
                bool allZero = true;
                for (int v : arr) {
                    if (v != 0) { allZero = false; break; }
                }

                if (allZero) ++answer;            // count this starting selection if valid
            }
        }

        return answer;                            // return total valid selections
    }
};

