class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fast =0 ;
        int slow = 0;
        int n = s.length();
        int MaxCount = 0;
        
        while (fast < n) {
            for (int i = slow; i < fast; i++) {
                if (s[i] == s[fast]) {
                    slow = i + 1;
                    break;
                }
            }           
            MaxCount = max(MaxCount, fast - slow + 1);           
            fast++;
        }
        return MaxCount;
    }
};
