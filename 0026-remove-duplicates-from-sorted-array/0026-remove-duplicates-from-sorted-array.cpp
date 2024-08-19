class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       set<int> myset;
       for(int i:nums){
        myset.insert(i);
        
       }
       int k=0;
       for(int i:myset){
        nums[k]=i;
        k++;
       } 
     return myset.size();
    }
};