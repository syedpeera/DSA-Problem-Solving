class Solution {
    public void findCombinationSum(int index, int candidates[], int target, List<List<Integer>> result, List<Integer> ds){
        if(index == candidates.length){
            if(target == 0){
                result.add(new ArrayList<>(ds));
            }
            return;
        }
        if(candidates[index]<=target){
            ds.add(candidates[index]);
            findCombinationSum(index, candidates, target-candidates[index], result, ds);
            ds.remove(ds.size()-1);
        }
        findCombinationSum(index+1, candidates, target, result, ds);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        findCombinationSum(0, candidates, target, result, new ArrayList<>());
        return result;
    }
}