class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //swap sort algorithm
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=j){
                return j;
            }
        }
        
        return n;
    }
};