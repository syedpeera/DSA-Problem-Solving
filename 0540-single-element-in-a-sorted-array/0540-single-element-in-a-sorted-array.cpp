class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else{
            if(nums[0]!=nums[1]){
                return nums[0];
            }
            else if(nums[n-1]!=nums[n-2]){
                return nums[n-1];
            }
        }
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if(((mid%2)==0 && nums[mid]==nums[mid+1]) || ((mid%2)==1 && nums[mid]==nums[mid-1])){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};