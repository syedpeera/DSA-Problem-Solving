class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maximumProduct=INT_MIN;
        int prefix=1;
        int suffix=1;
        for(int i=0;i<n;i++){
            prefix *= nums[i];
            maximumProduct = max(maximumProduct, prefix);
            if(nums[i]==0){
                prefix=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            suffix *= nums[i];
            maximumProduct = max(maximumProduct, suffix);
            if(nums[i]==0){
                suffix=1;
            }
        }
        return maximumProduct;
    }
};