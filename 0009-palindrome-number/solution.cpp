class Solution {
public:
    bool isPalindrome(int x) {
        int res = 0;
        int dup = x;
         if (x < 0) {
            return false;
        }
        while(x>0){
            int temp = x%10;
            if (res > INT_MAX / 10) return false;
            res = res*10 + temp;
            x = x/10;
        }
        return dup == res;
        
    }
};
