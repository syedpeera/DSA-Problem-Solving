class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        int n=nums.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
    int findPivot(vector<int>& nums, int target){
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid;
            }
            else if(nums[left]<=nums[mid] && nums[mid]>=nums[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index = findPivot(nums, target); // index of the minimum element
        int leftSearch = binarySearch(nums, target, 0, index-1);
        int rightSearch = binarySearch(nums, target, index, n-1);
        if(leftSearch==-1){
            return rightSearch;
        }
        else{
            return leftSearch;
        }
    }
};