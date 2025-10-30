#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long ans = 0;         // use long long to be safe with sums
        int prev = 0;              // previous value (virtual target[-1] = 0)

        for (int x : target) {
            if (x > prev) {       // only positive rises contribute
                ans += (long long)(x - prev);
            }
            prev = x;             // move window
        }

        return (int)ans;          // problem guarantees fits in 32-bit int
    }
};

