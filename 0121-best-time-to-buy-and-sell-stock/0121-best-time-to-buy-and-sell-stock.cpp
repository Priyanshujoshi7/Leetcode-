class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyPrice = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            
            profit = max(profit,prices[i]-buyPrice);
            buyPrice = min(buyPrice,prices[i]);

        }
        return profit;
        
    }
};