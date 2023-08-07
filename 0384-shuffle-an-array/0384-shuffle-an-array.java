class Solution {
    private int[] original;
    private int[] shuffled;
    private Random rand = new Random();

    public Solution(int[] nums) {
        original = nums.clone();
        shuffled = nums.clone();
    }
    
    public int[] reset() {
        return original;
    }
    
    public int[] shuffle() {
        int n = shuffled.length;
        for(int i=n-1; i>=0; i--){
            int j = rand.nextInt(i+1);
            int temp = shuffled[i];
            shuffled[i] = shuffled[j];
            shuffled[j] = temp;
        }
        return shuffled;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */