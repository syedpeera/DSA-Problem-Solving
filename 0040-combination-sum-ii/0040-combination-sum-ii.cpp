class Solution {
public:
    void findCombinationSum2(int index, vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &ds){
        if(target == 0){
            result.push_back(ds);
        }
        
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            ds.push_back(candidates[i]);
            findCombinationSum2(i+1, candidates, target - candidates[i], result, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinationSum2(0, candidates, target, result, ds);
        return result;
    }
};