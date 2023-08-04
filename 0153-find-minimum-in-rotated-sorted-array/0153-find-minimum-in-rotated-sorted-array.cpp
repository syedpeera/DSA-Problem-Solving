class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int result = INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[left] <= nums[mid]){
                result = min(result, nums[left]);
                left = mid + 1;
            }
            else{
                result = min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};