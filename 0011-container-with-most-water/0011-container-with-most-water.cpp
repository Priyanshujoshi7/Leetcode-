class Solution {
public:
    int maxArea(vector<int>& height) {
        // if(height.size() ==1) return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left<right){
            int current_area = min(height[left],height[right]) * (right-left);
            maxArea = max(maxArea,current_area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;


        
    }
};