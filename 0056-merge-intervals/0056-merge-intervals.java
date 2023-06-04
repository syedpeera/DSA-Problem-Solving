class Solution {
    public int[][] merge(int[][] intervals) {
        int n=intervals.length;
        List<int[]> result = new ArrayList<>();
        
        //Sort based on start time of the intervals
        Arrays.sort(intervals, (a,b) -> a[0]-b[0]);
        
        for(int i=0;i<n;i++){
            if(result.isEmpty() || result.get(result.size()-1)[1] < intervals[i][0]){
                result.add(intervals[i]);
            }
            else{
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], intervals[i][1]);
            }
        }
        return result.toArray(new int[result.size()][]);
    }
}