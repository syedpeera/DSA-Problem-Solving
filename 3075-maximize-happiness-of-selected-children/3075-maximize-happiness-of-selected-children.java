class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        
        for (int h : happiness) {
            pq.add(h);
        }

        long totalHappinessSum = 0;
        int turns = 0;

        for (int i = 0; i < k; i++) {
        
            totalHappinessSum += Math.max(pq.poll() - turns, 0);

            turns++;
        }

        return totalHappinessSum;
    }
}