class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //Sort the Intervals based on start time
        sort(intervals.begin(), intervals.end(), compare);
        //End time of first interval
        int end = intervals[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(end > intervals[i][0]){
                count++; //Overlapping interval found, increment count
                end = min(end, intervals[i][1]); //Update end time
            }
            else{
                end = intervals[i][1]; //Non-overlapping interval, update end time
            }
        }
        return count;
    }
};