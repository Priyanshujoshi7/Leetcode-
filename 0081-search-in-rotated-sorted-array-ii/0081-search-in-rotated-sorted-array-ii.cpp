class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        sort(nums.begin(),nums.end());
        while(start<=end){
            mid = start+(end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};