#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Step 1: Create a frequency map to count occurrences of each element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;  // Increase count for this element
        }

        // Step 2: Find the maximum frequency among all elements
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second); // keep track of max frequency
        }

        // Step 3: Count how many elements in nums have this max frequency
        int count = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                count += p.second;  // add all occurrences of this element
            }
        }

        return count; // Step 4: Return the total count
    }
};

