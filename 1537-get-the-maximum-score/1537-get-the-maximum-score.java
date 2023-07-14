class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        long sum1 = 0, sum2 = 0;
        long result = 0;
        int i = 0, j = 0;
        final int MOD = (int) 1e9 + 7;
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
                result = result + nums1[i] + Math.max(sum1, sum2);
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
        result = result + Math.max(sum1, sum2);
        
        return (int) (result % MOD);
    }
}