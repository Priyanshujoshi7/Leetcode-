class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    nums2[j] = -1; // Mark this element as used to avoid duplicate matches
                    break; // Exit the inner loop since the match is found
                }
            }
        }
        return result;
    }
};
