class Solution {
public:
    // Return type changed to long long to avoid 32-bit overflow
    long long removeZeros(long long n) {
        string s = to_string(n);
        string res;
        for (char c : s) {
            if (c != '0') res.push_back(c);
        }
        if (res.empty()) return 0LL;      // if n was 0 or all zeros
        return stoll(res);                // convert to long long
    }
};

