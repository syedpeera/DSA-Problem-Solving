class Solution {
public:
    void findCombinationSum(int index, vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &ds){
        if(index == candidates.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            findCombinationSum(index, candidates, target-candidates[index], result, ds);
            ds.pop_back();
        }
        findCombinationSum(index+1, candidates, target, result, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        findCombinationSum(0, candidates, target, result, ds);
        return result;
    }
};