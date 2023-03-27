class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n=arr.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};