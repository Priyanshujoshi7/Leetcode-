class Solution {
public:
    bool check(vector<int>& nums) {
        //made a counter
        int count = 0;
        //To overcome error
        int size = nums.size();
        // running a loop to compare elements if count is less than or equal to one 
        // it's  okay  but  greater than that is not
        for(int i = 0; i < size; i++){
            // diving the next element by modulus as when i=4 last element it compares to first element
            if(nums[i] > nums[(i+1) % size]){
                count++;
            }
        }
        //returning true or false
        return count <= 1;
    }
};