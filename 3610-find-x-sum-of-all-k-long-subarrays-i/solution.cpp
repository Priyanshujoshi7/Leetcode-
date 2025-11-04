class Solution {
public:
    // Alias for better readability — represents a pair of (frequency, number)
    using int2 = pair<int, int>;

    // ------------------------
    // \U0001f539 Helper Function: x_sum
    // ------------------------
    // Calculates the "x-sum" of the current frequency list
    // freq = array of pairs {frequency, value}
    // k = window size (not directly used here)
    // x = top 'x' most frequent elements to include in the sum
    static int x_sum(const auto& freq, int k, int x) {

        // Make a copy of freq to safely modify (we’ll sort this copy)
        auto freq2 = freq;

        // Sort the frequency pairs in descending order:
        // 1️⃣ Higher frequency first
        // 2️⃣ If frequencies are equal → higher number first
        sort(freq2.begin(), freq2.end(), greater<int2>());

        int sum = 0; // To store the computed x-sum

        // Pick top 'x' most frequent elements
        for (int i = 0; i < x; i++) {
            auto [f, num] = freq2[i];  // Structured binding: f = frequency, num = value

            // If there are no more elements (frequency 0), stop
            if (f == 0) break;

            // Add to total sum = value * its frequency
            sum += num * f;
        }

        return sum; // Return computed x-sum for this subarray
    }

    // -----------------------------------------
    // \U0001f539 Main Function: findXSum (LeetCode 3318)
    // -----------------------------------------
    // Given nums[], find x-sum for every subarray of size k
    static vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();  // Total elements
        const int sz = n - k + 1;   // Total possible subarrays of length k
        vector<int> ans(sz);        // To store results

        // Frequency tracker for values 1–50 (since nums[i] ≤ 50)
        // Each element: {frequency, number}
        array<int2, 51> freq;
        freq.fill({0, 0});  // Initialize all frequencies to 0

        // Step 1️⃣: Build frequency map for the first window of size k
        for (int r = 0; r < k; r++) {
            int z = nums[r];
            freq[z].second = z;  // Store the number
            freq[z].first++;     // Increment its frequency
        }

        // Step 2️⃣: Compute x-sum for the first window
        ans[0] = x_sum(freq, k, x);

        // Step 3️⃣: Slide the window one element at a time
        for (int l = 1, r = k; l < sz; l++, r++) {
            int L = nums[l - 1];  // Element going out of window (leftmost)
            int R = nums[r];      // Element coming into window (rightmost)

            // Update frequencies
            freq[L].first--;      // Decrease frequency of outgoing element
            freq[R].first++;      // Increase frequency of incoming element
            freq[R].second = R;   // Update value for new element

            // Recalculate x-sum for the new window
            ans[l] = x_sum(freq, k, x);
        }

        return ans; // Return all results
    }
};

// ----------------------------------------------------
// \U0001f539 Fast I/O Initialization (Optional but Good Practice)
// ----------------------------------------------------
// This improves input/output speed in competitive programming
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';  // Dummy return just to run this before main()
}();

