class Solution {
private:
    vector<int> original;
    vector<int> shuffled;
public:
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int n = shuffled.size();
        for(int i=n-1; i>=0; i--){
            int j = rand() % (i+1);
            int temp = shuffled[i];
            shuffled[i] = shuffled[j];
            shuffled[j] = temp;
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */