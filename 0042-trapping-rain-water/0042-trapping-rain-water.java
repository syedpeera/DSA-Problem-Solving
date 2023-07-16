class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left = 1;
        int right = n - 2;
        int leftMax = height[0];
        int rightMax = height[n-1];
        int totalWater = 0;
        while(left <= right){
            if(leftMax < rightMax){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }
                else{
                    totalWater = totalWater + (leftMax - height[left]);
                }
                left++;
            }
            else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }
                else{
                    totalWater = totalWater + (rightMax - height[right]);
                }
                right--;
            }
        }
        return totalWater;
    }
}