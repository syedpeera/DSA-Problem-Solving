class Solution {
    public int minOperations(String s) {
        int n = s.length();
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<n;i++){
            if((i%2==0 && s.charAt(i)=='0') || (i%2!=0 && s.charAt(i)=='1')){
                count1++;
            }
            else if((i%2==0 && s.charAt(i)=='1') || (i%2!=0 && s.charAt(i)=='0')){
                count2++;
            }
        }
        return Math.min(count1,count2);
    }
}