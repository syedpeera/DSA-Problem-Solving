class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        vector<int> ans;
        int length = nums.size();
        for(int i=0; i<length;i++)
        {
            int key = target - nums[i];
            if(m.find(key)!=m.end())
            {
                ans.push_back(m[key]);
                ans.push_back(i);
            }
            else
            {
                m[nums[i]]=i;
            }
        }
        return ans;
    }  
};