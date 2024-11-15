class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count =0;
        int oddcount =0;
        unordered_map <int,int> mpp;
        mpp[0] =1;

        for(int num:nums){
            if(num%2 !=0){
                oddcount++;
            }
            if(mpp.find(oddcount-k)!= mpp.end()){
                count+= mpp[oddcount -k];
            }
            mpp[oddcount]++;
        }
        return count;
        
    }
};