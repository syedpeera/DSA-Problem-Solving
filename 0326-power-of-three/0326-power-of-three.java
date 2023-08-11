class Solution {
    public boolean isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        // Largest power of 3 within the int range is 3^19
        int maxPowerOfThree = 1162261467; // 3^19
        return maxPowerOfThree % n == 0;
    }
}