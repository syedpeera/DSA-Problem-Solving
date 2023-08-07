class Solution {
    public int[] sumZero(int n) {
        int result[] = new int[n];
        int j=0;
        for(int i=1; i<=n/2; i++){
            result[j++] = i;
            result[j++] = -i;
        }
        if(n%2 != 0){
            result[j] = 0;
        }
        return result;
    }
}