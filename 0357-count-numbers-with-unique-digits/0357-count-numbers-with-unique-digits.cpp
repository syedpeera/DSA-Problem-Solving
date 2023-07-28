class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        int result = 10;
        int uniqueDigits = 9;
        int availableNumbers = 9;
        while(n > 1 && availableNumbers > 0){
            uniqueDigits = uniqueDigits * availableNumbers;
            result = result + uniqueDigits;
            availableNumbers--;
            n--;
        }
        return result;
    }
};
