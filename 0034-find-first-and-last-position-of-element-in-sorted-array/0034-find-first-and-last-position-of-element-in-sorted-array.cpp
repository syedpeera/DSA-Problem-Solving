class Solution {
public:
    int search(vector<int>& nums, int target, bool flag){
        int left=0;
        int right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                index=mid;
                if(flag==true){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(search(nums, target, true));
        ans.push_back(search(nums, target, false));
        return ans;
    }
};