class Solution {
public:
    int maximum69Number (int num) {
        vector <int> count;
        while(num>0){
            count.push_back(num%10);
            num = num/10;
        }
        reverse(count.begin(), count.end());
        for(int i =0;i<count.size();i++){
            if(count[i]==6){
                count[i]=9;
                break;
            }
        }
        reverse(count.begin(), count.end());
        long long ans = 0;
        for (int i = count.size() - 1; i >= 0; i--) {
            if (i < count.size()) {
                ans += count[i] * pow(10, i);
            }
        }

        return ans;
    }
};

