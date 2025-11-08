class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;

        // The key trick:
        // The minimum operations follow a known pattern where
        // the result is equal to n XOR (n >> 1) XOR (n >> 2) ... 
        // repeatedly until n becomes 0.
        //
        // This works because the number of operations forms a
        // "reflected Gray code" distance from 0.
        // Each shift aligns higher bits down so XOR accumulates
        // the necessary flips for each bit level.

        while (n) {
            res ^= n;   // accumulate XOR with current bits of n
            n >>= 1;    // shift right to process next higher bit
        }

        // Final res is the minimal number of operations
        return res;
    }
};

