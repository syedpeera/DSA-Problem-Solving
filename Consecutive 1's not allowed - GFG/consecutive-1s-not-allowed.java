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
            int n = Integer.parseInt(br.readLine().trim());

            long ans = new Solution().countStrings(n);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long countStrings(int n) {
        long zeroEnd = 1;
        long oneEnd = 1;
        long sum = zeroEnd+oneEnd;
        if(n==1){
            return sum;
        }
        long i=2;
        while(i<=n){
            oneEnd = zeroEnd%1000000007;
            zeroEnd = sum%1000000007;
            sum = (zeroEnd + oneEnd)%1000000007;
            i++;
        }
        return sum%1000000007;
    }
}