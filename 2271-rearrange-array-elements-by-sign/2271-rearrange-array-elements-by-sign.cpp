class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  // To store the rearranged array
        int posIndex = 0;  // Index to place positive numbers
        int negIndex = 1;  // Index to place negative numbers
        
        // Iterate over the input array and place positive and negative numbers     alternately
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[posIndex] = nums[i];  // Place positive numbers at even indices
                posIndex += 2;
            } else {
                result[negIndex] = nums[i];  // Place negative numbers at odd indices
                negIndex += 2;
            }
        }
        
        return result;
    }
};
