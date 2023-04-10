class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        int left=matrix[0][0];
        int right=matrix[row-1][col-1];
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=0;
            
            for(int i=0;i<row;i++){
                int newLeft=0;
                int newRight=col-1;
                while(newLeft<=newRight){
                    int newMid=newLeft+(newRight-newLeft)/2;
                    if(matrix[i][newMid]<=mid){
                        newLeft=newMid+1;
                    }
                    else{
                        newRight=newMid-1;
                    }
                }
                count=count+newLeft;
            }
            
            if(count<k){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};