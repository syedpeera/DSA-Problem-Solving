class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        long long int ans=-1;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            long long int square=mid*mid;
            if(square==x){
                return mid;
            }
            else if(square<x){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return  ans;
    }
};