class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;
        int max = *max_element(piles.begin(), piles.end());
        
        // Binary search for the minimum eating speed `k`
        while (start < max) {
            int k = start + (max - start) / 2;
            int hours = 0;
            
            // Calculate hours needed with the current speed `k`
            for (int pile : piles) {
                hours += ceil((double)pile / k);
            }
            
            if (hours <= h) {
                max = k;  // Try a lower speed
            } else {
                start = k + 1;  // Increase the speed
            }
        }
        
        return start;
    
    }
};