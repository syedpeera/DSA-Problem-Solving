class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;

        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
        }
        result.push_back(dq.front());
        for(int i=k; i<n; i++){
            
            if(dq.front() == nums[i-k]){
                dq.pop_front();
            }
            
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
            result.push_back(dq.front());
        }
        
        return result;
    }
};