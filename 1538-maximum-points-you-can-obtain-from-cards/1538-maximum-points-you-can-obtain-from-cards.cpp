class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result =0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++) result+=cardPoints[i];

        int curr = result;
        for(int i=k-1;i>=0;i--){
            curr -= cardPoints[i];
            curr += cardPoints[n-k+i];

            result = max(result,curr);
        }
        return result;
        
    }
};