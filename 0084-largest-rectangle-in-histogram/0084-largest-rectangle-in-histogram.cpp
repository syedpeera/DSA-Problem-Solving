class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        //NSL, index
        stack<pair<int, int>> bucket1;
        //NSR, index
        stack<pair<int, int>> bucket2;
        int pseudoIndex=-1;
        vector<int> left;
        //NSL - Next Smallest to Left 
        for(int i=0;i<n;i++){
            if(bucket1.empty()){
                left.push_back(pseudoIndex);
            }
            else if(!bucket1.empty() && bucket1.top().first<heights[i]){
                left.push_back(bucket1.top().second);
            }
            else{
                while(!bucket1.empty() && bucket1.top().first>=heights[i]){
                    bucket1.pop();
                }
                if(bucket1.empty()){
                    left.push_back(pseudoIndex);
                }
                else{
                    left.push_back(bucket1.top().second);
                }
            }
            bucket1.push({heights[i],i});
        }
        pseudoIndex=n;
        vector<int> right;
        //NSR - Next Smallest to Right
        for(int i=n-1;i>=0;i--){
            if(bucket2.empty()){
                right.push_back(pseudoIndex);
            }
            else if(!bucket2.empty() && bucket2.top().first<heights[i]){
                right.push_back(bucket2.top().second);
            }
            else{
                while(!bucket2.empty() && bucket2.top().first>=heights[i]){
                    bucket2.pop();
                }
                if(bucket2.empty()){
                    right.push_back(pseudoIndex);
                }
                else{
                    right.push_back(bucket2.top().second);
                }
            }
            bucket2.push({heights[i],i});            
        }
        reverse(right.begin(),right.end());
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int width = ((right[i]-left[i]-1)*heights[i]);
            maxArea=max(maxArea,width);
        }
        return maxArea;
    }
};