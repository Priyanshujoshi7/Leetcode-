class Solution {
public:

    int SubarrayWithSumLessThanGoal(vector<int>& nums, int goal){
        int l=0,r=0,n=nums.size();
        int sum = 0,cnt = 0;
        if(goal < 0) return 0; 
        while(r<n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            } 
            cnt += (r - l + 1); 
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a = SubarrayWithSumLessThanGoal(nums, goal);
        int b = SubarrayWithSumLessThanGoal(nums, goal - 1);

        return a - b;
    }
};