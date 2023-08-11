class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for(int i=2; i*i<n; i++){
            if(!isPrime[i]){
                continue;
            }
            for(int j=i*i; j<n; j=j+i){
                if(isPrime[j]){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};