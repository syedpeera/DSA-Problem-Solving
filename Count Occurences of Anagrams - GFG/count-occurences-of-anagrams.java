//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String txt = br.readLine().trim();
            String pat = br.readLine().trim();

            int ans = new Solution().search(pat, txt);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Solution {
    int search(String pat, String txt) {
        int n = txt.length();
        int k = pat.length();
        int count = 0;
        
        int txtFreq[] = new int[26];
        int patFreq[] = new int[26];
        
        for(int i=0; i<k; i++){
            txtFreq[txt.charAt(i) - 'a']++;
            patFreq[pat.charAt(i) - 'a']++;
        }
        
        for(int i=k; i<n; i++){
            if(Arrays.equals(txtFreq, patFreq)){
                count++;
            }
            
            //Remove the leftmost character from the window
            txtFreq[txt.charAt(i-k) - 'a']--;
            
            //Add the rightmost character to the window
            txtFreq[txt.charAt(i) - 'a']++;
        }
        
        if(Arrays.equals(txtFreq, patFreq)){
            count++;
        }
        
        return count;
    }
}