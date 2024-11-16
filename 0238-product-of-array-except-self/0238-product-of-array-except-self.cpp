class Solution {
public:
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixArr(n, 1);
        vector<int> suffixArr(n, 1);
        vector<int> result(n, 1);
        int prefix =1;
        int suffix =1;
        for(int i=0;i<n;i++){
            prefixArr[i] = prefix;
            prefix *= nums[i];
        }
        for(int i =n-1;i>=0;i--){
            suffixArr[i] = suffix;
            suffix *= nums[i];
        }
        for(int i=0;i<n;i++){
            result[i]= suffixArr[i]*prefixArr[i];
        }
        return result;
        

        
    }
};
