class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                index=mid;
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return index;
    }
    int lastOccurrence(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                index=mid;
                left=mid+1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccurrence(nums, target));
        ans.push_back(lastOccurrence(nums, target));
        return ans;
    }
};