class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1; // [0, 1] -> 2
        for(int i=0; i<n; i++){
            sum = sum + ((nums[i] == 0)? -1 : 1);
            if(map.find(sum) != map.end()){
                result = max(result, i - map[sum]);
            }
            else{
                map[sum] = i;
            }
        }
        return result;
    }
};