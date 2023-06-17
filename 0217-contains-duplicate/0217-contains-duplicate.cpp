class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        set<int> setBucket;
        for(int i=0;i<n;i++){
            if(setBucket.find(nums[i])!=setBucket.end()){
                return true;
            }
            setBucket.insert(nums[i]);
        }
        return false;
    }
};