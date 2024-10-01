class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;

        for (int i=0;i<nums.size();i++) {
            //adding the subarray sum
            sum = sum+nums[i];
            //if sum is greater than max? put sum value in max
            if(sum>max){
                max = sum;
            }
            //if the sum is less than 0? re-initialise
            if(sum<0){
                sum = 0;
            }
            
        }
        //returning the max subarray sum
        return max;        
    }
}; 