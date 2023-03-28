class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> ans;
        //storing distance and co-ordinates
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for(int i=0;i<n;i++){
            int distance = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            maxHeap.push({distance,{points[i][0],points[i][1]}});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()){
            vector<int> temp;
            temp.push_back(maxHeap.top().second.first);
            temp.push_back(maxHeap.top().second.second);
            ans.push_back(temp);
            maxHeap.pop();
        }
        return ans;
    }
};