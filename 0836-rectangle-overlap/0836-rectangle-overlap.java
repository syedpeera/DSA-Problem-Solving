class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        /* non - overlapping conditions
           case 1: rec2 is above rec1 (consider y-axis as reference)
           case 2: rec2 is below rec1 (consider y-axis as reference)
           case 3: rec2 is to the left side of rec1 (consider x-axis as reference)
           case 4: rec2 is to the right side of rec1 (consider x-axis as reference)
        */
        
        if((rec2[1] >= rec1[3]) || (rec2[3] <= rec1[1]) || (rec2[2] <= rec1[0]) || (rec2[0] >= rec1[2])){
            return false;
        }
        
        return true;
    }
}