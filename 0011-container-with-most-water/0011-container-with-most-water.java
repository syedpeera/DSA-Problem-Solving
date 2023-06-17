class Solution {
    public int maxArea(int[] height) {
        int left=0;
        int right=height.length-1;
        int maxWater=0;
        while(left<=right){
            if(height[left]>height[right]){
                maxWater = Math.max(maxWater, (right-left)*height[right]);
                right--;
            }
            else{
                maxWater = Math.max(maxWater, (right-left)*height[left]);
                left++;
            }
        }
        return maxWater;
    }
}