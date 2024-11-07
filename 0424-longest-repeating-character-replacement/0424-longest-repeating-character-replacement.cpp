class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen =0;
        int i=0,j=0;
        int maxCount = 0; 
        unordered_map<char, int> count;
        
        while(j<s.size()){
            count[s[j]]++; 
            maxCount = max(maxCount, count[s[j]]); 
            if ((j - i + 1) - maxCount > k) {
                count[s[i]]--; 
                i++; 
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
        
    }
};