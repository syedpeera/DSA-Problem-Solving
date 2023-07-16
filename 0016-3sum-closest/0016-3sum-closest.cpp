class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long long closestSum = INT_MAX;
        int j = 0, k = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            j = i + 1;
            k = n - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(closestSum - target)){
                    closestSum = sum;
                }
                
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        return closestSum;
    }
};