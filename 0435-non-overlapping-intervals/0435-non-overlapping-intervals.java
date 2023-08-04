class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n=intervals.length;
        //Sort the Intervals based on start time
        Arrays.sort(intervals, (a, b) -> a[0]-b[0]);
        //End time of first interval
        int end = intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(end > intervals[i][0]){
                count++; //Overlapping interval found, increment count
                end = Math.min(end, intervals[i][1]); //Update end time
            }
            else{
                end = Math.max(end, intervals[i][1]); //Non-overlapping interval, update end time
            }
        }
        return count;
    }
}