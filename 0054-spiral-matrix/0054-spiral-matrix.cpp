class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int direction=0;
        //0 means left to right
        //1 means top to bottom
        //2 means right to left
        //3 means bottom to top
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        while(top <= bottom && left <= right)
        {
            if(direction==0)
            {
                for(int i=left;i<=right && top<=bottom;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction==1)
            {
                for(int i=top;i<=bottom && left<=right;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction==2)
            {
                for(int i=right;i>=left && top<=bottom;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(direction==3)
            {
                for(int i=bottom;i>=top && left<=right;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return ans;
    }
};