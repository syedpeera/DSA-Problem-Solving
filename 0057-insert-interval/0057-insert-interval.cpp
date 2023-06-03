class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n = intervals.size();
        vector<vector<int>> result;
        //Add all intervals before newInterval that don't overlap
        while(i<n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        // Merge overlapping intervals
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        // Add the merged interval
        result.push_back(newInterval);
        // Add all intervals after newInterval that don't overlap
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};