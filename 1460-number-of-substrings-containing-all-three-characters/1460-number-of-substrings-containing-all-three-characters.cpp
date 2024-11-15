class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();

        int l=0, r =0;
        int count = 0;
        unordered_map<char,int> mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                count+= n-r;
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;


        
    }
};