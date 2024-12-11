class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        result.insert(result.end(), nums1.begin(), nums1.end());
        result.insert(result.end(), nums2.begin(), nums2.end());
        sort(result.begin(), result.end());

        int n = result.size();
        if (n % 2 != 0) {
            // Odd-length array
            int mid = n / 2;
            return result[mid];
        } else {
            // Even-length array
            int mid = n / 2;
            return (result[mid] + result[mid - 1]) / 2.0;
        }
    }
};
