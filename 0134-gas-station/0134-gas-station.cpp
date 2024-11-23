class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas =0;
        int totalCost = 0;
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost>totalGas){
            return -1;
        }
        int currentGas= 0;
        int start=0;
        for(int i=0;i<n;i++){
            currentGas += gas[i]-cost[i];
            if(currentGas<0){
                currentGas =0;
                start = i+1;
            }
        }
        return start;
        
    }
};