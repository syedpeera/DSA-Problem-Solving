class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size(), minDiff = INT_MAX;
        if (numsSize <= 4) return 0;

        partial_sort(nums.begin(), nums.begin() + 4, nums.end());

        nth_element(nums.begin() + 4, nums.begin() + (numsSize - 4),
                    nums.end());
        
        sort(nums.begin() + (numsSize - 4), nums.end());

        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};