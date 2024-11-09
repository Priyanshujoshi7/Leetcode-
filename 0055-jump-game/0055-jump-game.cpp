class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump =0;
        int l =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(jump<i){
                return false;
            }
            jump = max(jump,i+nums[i]);
        }
        return true;
        
    }
};