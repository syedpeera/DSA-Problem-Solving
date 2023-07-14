class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        long sum1 = 0, sum2 = 0;
        long result = 0;
        int i = 0, j = 0;
        int MOD = 1e9 + 7;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                sum1 = sum1 + nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]){
                sum2 = sum2 + nums2[j];
                j++;
            }
            else{
                result = result + nums1[i] + max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < n1){
            sum1 = sum1 + nums1[i];
            i++;
        }
        while(j < n2){
            sum2 = sum2 + nums2[j];
            j++;
        }
        result = result + max(sum1, sum2);
        
        return (int) (result % MOD);
    }
};