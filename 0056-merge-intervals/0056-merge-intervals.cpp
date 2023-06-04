class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        //Sort based on start time of the intervals
        sort(intervals.begin(), intervals.end(), compare);
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(result.empty() || result[result.size()-1][1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
            }
        }
        return result;
    }
};