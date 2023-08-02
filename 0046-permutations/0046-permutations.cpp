class Solution {
public:
    void solvePermute(vector<vector<int>> &result, vector<int> &nums, int start, int end){
        if(start == end){
            result.push_back(nums);
            return;
        }
        for(int i=start; i<=end; i++){
            swap(nums[start], nums[i]);
            solvePermute(result, nums, start+1, end);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        solvePermute(result, nums, 0, n-1);
        return result;
    }
};