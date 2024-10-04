class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;  
        int longestStreak = 1;
        int currentStreak =1;  
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if (nums[i] != nums[i + 1]) { 
                if(nums[i]==nums[i+1]-1){
                    currentStreak++;
                }else{
                    longestStreak = max(currentStreak,longestStreak);
                    currentStreak =1;
                }
            }   
        }
        int result = max(currentStreak,longestStreak);
        return result;
    }
};