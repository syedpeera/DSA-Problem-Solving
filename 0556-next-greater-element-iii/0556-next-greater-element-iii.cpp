class Solution {
public:
    int nextGreaterElement(int n) {
        int input = n;
        vector<int> digits;
        while(n!=0){
            digits.push_back(n%10);
            n=n/10;
        }
        reverse(digits.begin(), digits.end());
        int index1=-1;
        int index2=-1;
        for(int i=digits.size()-1;i>0;i--){
            if(digits[i]>digits[i-1]){
                index1=i-1;
                break;
            }
        }
        if(index1==-1){
            reverse(digits.begin(), digits.end());
        }
        else{
            for(int i=digits.size()-1;i>0;i--){
                if(digits[i]>digits[index1]){
                    index2=i;
                    break;
                }
            }
            swap(digits[index1], digits[index2]);
            reverse(digits.begin()+index1+1, digits.end());
        }
        long num=0;
        for(int i=0;i<digits.size();i++){
            num = num*10 + digits[i];
        }
        if(num <= input || num > INT_MAX){
            return -1;
        }
        return num;
    }
};