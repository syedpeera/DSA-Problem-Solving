class Solution {
public:
    struct comparator{
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        }  
    };
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> frequencyMap;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for(int i=0;i<n;i++){
            frequencyMap[nums[i]]++;
        }
        for(auto x: frequencyMap){
             pq.push({x.first, x.second});
        }
        while(!pq.empty()){
            int temp = pq.top().second;
            while(temp--){
                ans.push_back(pq.top().first);
            }
            pq.pop();
        }
        return ans;
    }
};