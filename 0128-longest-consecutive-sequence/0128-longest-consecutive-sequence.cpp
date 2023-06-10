class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> setBucket;
        int n=nums.size();
        for(int i=0;i<n;i++){
            setBucket.insert(nums[i]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            int currentElement = nums[i];
            int previousElement = currentElement-1;
            int count=1;
            if(setBucket.find(previousElement)==setBucket.end()){
                while(setBucket.find(currentElement+1)!=setBucket.end()){
                    currentElement++;
                    count++;
                }
            }
            result=max(result, count);
        }
        return result;
    }
};