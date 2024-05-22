class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int masksize = (1<<size);
        vector<vector<int>> result;
        for(int mask=0;mask<masksize;mask++)
        {
            vector<int> ans;
            for(int i=0;i<size;i++)
            {
                if((mask & (1<<i))!=0)
                {
                    ans.push_back(nums[i]);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};