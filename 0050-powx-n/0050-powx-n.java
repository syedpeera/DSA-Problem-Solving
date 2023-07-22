class Solution {
    public double myPow(double x, int n) {
        double result = 1.0;
        long N = n;
        if(N < 0){
            x = 1.0 / x;
            N = -1 * N;
        }
        while(N > 0){
            if(N % 2 == 1){
                result = result * x;
            }
            x = x * x;
            N = N / 2;
        }
        return result;
    }
}