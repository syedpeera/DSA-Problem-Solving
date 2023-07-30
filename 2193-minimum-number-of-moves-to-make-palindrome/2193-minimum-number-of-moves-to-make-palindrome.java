class Solution {
    public void swap(char arr[], int i, int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public int minMovesToMakePalindrome(String s) {
        int minSwaps = 0;
        int left = 0;
        int right = s.length()-1;
        char arr[] = s.toCharArray();
        
        while(left < right){
            int l = left;
            int r = right;
            
            while(arr[l] != arr[r]){
                r--;
            }
            
            if(l == r){
                // No matching character found, swap with the adjacent right character
                swap(arr, r, r+1);
                minSwaps++;
                continue;
            }
            else{
                while(r < right){
                    // Swap characters to make them same
                    swap(arr, r, r+1);
                    minSwaps++;
                    r++;
                }
            }
            
            left++;
            right--;
        }
        return minSwaps;
    }
}