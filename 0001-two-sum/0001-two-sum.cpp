class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //element and index
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int x = target-nums[i];
            if(m.find(x)!=m.end())
            {
                ans.push_back(m[x]);
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