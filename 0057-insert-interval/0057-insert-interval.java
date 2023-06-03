class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int i=0;
        int n=intervals.length;
        List<int[]> result = new ArrayList<>();
        //Add all intervals before newInterval that don't overlap
        while(i<n && intervals[i][1] < newInterval[0]){
            result.add(intervals[i]);
            i++;
        }
        
        // Merge overlapping intervals
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = Math.min(intervals[i][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[i][1], newInterval[1]);
            i++;
        }
        
        // Add the merged interval
        result.add(newInterval);
        
        // Add all intervals after newInterval that don't overlap
        while(i<n){
            result.add(intervals[i]);
            i++;
        }
        
        return result.toArray(new int[result.size()][2]);
    }
}