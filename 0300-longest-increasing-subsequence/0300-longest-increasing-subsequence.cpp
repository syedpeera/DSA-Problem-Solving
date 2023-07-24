class Solution {
public:
    int cielBinarySearch(vector<int> &temp, int target){
        int left = 0;
        int right = temp.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(temp[mid] == target){
                return mid;
            }
            else if(temp[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int index = cielBinarySearch(temp, nums[i]);
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};