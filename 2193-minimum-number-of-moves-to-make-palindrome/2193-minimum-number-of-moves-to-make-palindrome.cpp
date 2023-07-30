class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int minSwaps = 0;
        int left = 0;
        int right = s.size()-1;
        
        while(left < right){
            int l = left;
            int r = right;
            
            while(s[l] != s[r]){
                r--;
            }
            
            if(l == r){
                // No matching character found, swap with the adjacent right character
                swap(s[r], s[r+1]);
                minSwaps++;
                continue;
            }
            else{
                // Swap characters to make them same
                while(r < right){
                    swap(s[r], s[r+1]);
                    minSwaps++;
                    r++;
                }
            }
            
            left++;
            right--;
        }
        return minSwaps;
    }
};