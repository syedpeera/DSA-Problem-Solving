class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            frequencyMap[nums[i]]++;
        }
        //Add elements in the heap with frequency, element as its sorted based on frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto x: frequencyMap){
            minHeap.push({x.second,x.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second); 
            minHeap.pop();
        }
        return ans;
    }
};