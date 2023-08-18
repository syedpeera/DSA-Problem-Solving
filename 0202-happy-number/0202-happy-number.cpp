class Solution {
public:
    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum = sum + digit * digit;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1 && set.find(n) == set.end()){
            set.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};