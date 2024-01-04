class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        int result = 0;
        for(int i=0; i<n; i++){
            map[nums[i]]++;
        }
        for(auto &element: map){
            int freq = element.second;
            if(freq == 1){
                return -1;
            }
            result = result + ceil((double)freq/3);
        }
        return result;
    }
};