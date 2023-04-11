class Solution {
public:
    bool isValid(vector<int>& weights, int days, int result){
        int count=1;
        int n=weights.size();
        int weight=0;
        for(int i=0;i<n;i++){
            weight=weight+weights[i];
            if(weight>result){
                count++;
                weight=weights[i];
            }
            if(count>days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxVal=INT_MIN;
        for(int i=0;i<n;i++){
            if(weights[i]>maxVal){
                maxVal=weights[i];
            }
            sum=sum+weights[i];   
        }
        int left=maxVal;
        int right=sum;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(weights, days, mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};