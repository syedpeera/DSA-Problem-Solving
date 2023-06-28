class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){
                count++;
            }
            else if(count == 0){
                candidate = nums[i];
                count=1;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};