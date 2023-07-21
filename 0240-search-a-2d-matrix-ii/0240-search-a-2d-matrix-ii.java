class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int i = 0;
        int j = matrix[0].length-1;
        int rowSize = matrix.length;
        int colSize = matrix[0].length;
        
        while(i >= 0 && j >= 0 && i < rowSize && j < colSize){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
}