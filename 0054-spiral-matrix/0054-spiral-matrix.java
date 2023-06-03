class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int top = 0;
        int bottom = matrix.length-1;
        int left = 0;
        int right = matrix[0].length-1;
        List<Integer> result = new ArrayList<>();
        int direction=0;
        //0 means move from left to right 
        //1 means move from top to bottom
        //2 means move from right to left
        //3 means move from bottom to top
        while(top<=bottom && left<=right){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    result.add(matrix[top][i]);
                }
                top++;
            }
            else if(direction==1){
                for(int i=top;i<=bottom;i++){
                    result.add(matrix[i][right]);
                }
                right--;
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){
                    result.add(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(direction==3){
                for(int i=bottom;i>=top;i--){
                    result.add(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return result;
    }
}