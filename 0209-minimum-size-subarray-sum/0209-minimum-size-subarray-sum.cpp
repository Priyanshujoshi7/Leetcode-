class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int len = INT_MAX;
        int minLen = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                len = j-i+1;
                sum -= nums[i];
                i++;
            }
            minLen = min(len, minLen);
            j++; // j ko baad me increase kr rhe hai, taki while loop k andar len shi calculate ho
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};