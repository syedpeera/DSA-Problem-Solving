class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;
        int sum = 0;
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            
            int compliment = sum - k;
            
            if(sumFreq.find(compliment) != sumFreq.end()){
                count = count + sumFreq[compliment];
            }
            
            sumFreq[sum]++;
        }
        return count;
    }
};