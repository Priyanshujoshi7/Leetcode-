class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int i =1;
        while(i < n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int currentPeak =0;
            while(i<n && ratings[i]>ratings[i-1]){
                currentPeak++;
                candies += currentPeak;
                i++;
            }
            if(i==n){
                return candies;
            }
            int currentValley =0;
            while(i<n && ratings[i]<ratings[i-1] ){
                currentValley++;
                candies+= currentValley;
                i++;
            }
            candies -= min(currentPeak,currentValley);
        }
        return candies;
    }
};