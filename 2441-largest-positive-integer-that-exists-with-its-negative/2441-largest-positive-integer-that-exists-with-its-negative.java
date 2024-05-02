class Solution {
    public int findMaxK(int[] nums) {
        int ans = -1;

        // Initialize a bitset to keep track of seen numbers
        BitSet seen = new BitSet(2048);

        for (int num : nums) {
            int absNum = Math.abs(num);

            // If the absolute value is greater than the current answer
            // and its negation was seen before,
            // update the answer
            if (absNum > ans && seen.get(-num + 1024))
                ans = absNum;
            // Mark the current number as seen
            seen.set(num + 1024);
        }

        return ans;
    }
}