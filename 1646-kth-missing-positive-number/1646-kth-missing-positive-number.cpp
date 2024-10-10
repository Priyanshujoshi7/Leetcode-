class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        vector<int> arr2;
        int n = arr.size();
        if (n == 0)
            return k;
        int last = arr[n - 1];
        for (int i = 1; i < last; i++)
        {
            arr2.push_back(i);
        }
        vector<int> difference;
        set_difference(arr2.begin(), arr2.end(), arr.begin(), arr.end(), back_inserter(difference));
        if (k > difference.size())
        {
            return last + (k - difference.size());
        }

        // Return the kth missing number
        return difference[k - 1];
    }
};