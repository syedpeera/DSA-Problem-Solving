class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]>nums[1]){
            return 0;
        }
        else if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int left=1;
        int right=n-2;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid>0 && mid<n-1){
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid+1]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};