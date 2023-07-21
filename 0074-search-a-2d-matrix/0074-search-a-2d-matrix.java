class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int left = 0;
        int right = (matrix.length * matrix[0].length)-1;
        int row = matrix.length;
        int col = matrix[0].length;
        while(left <= right){
            int i = left/col;
            int j = right%col;
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
}