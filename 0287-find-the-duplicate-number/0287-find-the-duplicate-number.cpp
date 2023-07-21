class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i < n){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        for(int j=0; j<n; j++){
            if(nums[j] != j+1){
                return nums[j];
            }
        }
        return -1;
    }
};