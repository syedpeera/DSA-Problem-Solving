class Solution {
    public void moveZeroes(int[] nums) {
        Stack<Integer> s = new Stack<>();
        int zeroCount=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                s.push(nums[i]);
            }
            else{
                zeroCount++;
            }
        }
        for(int i=nums.length-1;i>=0;i--){
            if(zeroCount>0){
                nums[i]=0;
                zeroCount--;
            }else{
                nums[i]=s.peek();
                s.pop();
            }
        }
    }
}