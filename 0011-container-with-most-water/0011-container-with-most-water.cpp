class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;
        while(left<=right){
            if(height[left]>height[right]){
                maxWater = max(maxWater, (right-left)*height[right]);
                right--;
            }
            else{
                maxWater = max(maxWater, (right-left)*height[left]);
                left++;
            }
        }
        return maxWater;
    }
};