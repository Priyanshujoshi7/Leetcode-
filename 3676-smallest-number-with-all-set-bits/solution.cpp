#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;                     // Start with 1 (binary: "1")

        // Keep creating numbers like: 1, 3, 7, 15, 31, ... (which are 2^k - 1)
        // until x becomes >= n
        while (x < n) {
            x = (x << 1) | 1;          // Left shift by 1 (multiply by 2), then OR with 1 to set all bits
        }

        // When x >= n, it's the smallest number having all bits = 1
        return x;
    }
};

