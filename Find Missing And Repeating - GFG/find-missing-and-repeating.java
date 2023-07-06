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
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a, n);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends


class Solve {
    int[] findTwoElement(int arr[], int n) {
        int xorResult = 0;
        for(int i=0;i<n;i++){
            xorResult ^= arr[i];
            xorResult ^= (i+1);
        }
        int rightMostSetBit = xorResult & ~(xorResult-1);
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if((arr[i] & rightMostSetBit)!=0){
                x ^= arr[i];
            }
            else{
                y ^= arr[i];
            }
            if(((i+1) & rightMostSetBit)!=0){
                x ^= (i+1);
            }
            else{
                y ^= (i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                return new int[]{x, y};
            }
        }
        return new int[]{y, x};
    }
}