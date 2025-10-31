class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // Create a hashmap to count the frequency of each number
        unordered_map<int, int> freq;
        
        // Count occurrences of each number in nums
        for (int num : nums) {
            freq[num]++;
        }
        
        // Vector to store the two sneaky (repeated) numbers
        vector<int> result;
        
        // Find numbers that appear twice
        for (auto& p : freq) {
            if (p.second == 2) {
                result.push_back(p.first);
            }
        }
        
        // Return the two numbers (order does not matter)
        return result;
    }
};

