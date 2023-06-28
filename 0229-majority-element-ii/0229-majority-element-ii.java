class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 0;
        for(int i=0;i<n;i++){
            if(candidate1==nums[i]){
                count1++;
            }
            else if(candidate2==nums[i]){
                count2++;
            }
            else if(count1==0){
                candidate1 = nums[i];
                count1=1;
            }
            else if(count2==0){
                candidate2 = nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(candidate1==nums[i]){
                count1++;
            }
            else if(candidate2==nums[i]){
                count2++;
            }
        }
        List<Integer> result = new ArrayList<>();
        int min = (n/3)+1;
        if(count1 >= min){
            result.add(candidate1);
        }
        if(count2 >= min){
            result.add(candidate2);
        }
        return result;
    }
}