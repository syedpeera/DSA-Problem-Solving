//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N, M, x, y;
            String S[] = read.readLine().split(" ");
            N = Integer.parseInt(S[0]);
            M = Integer.parseInt(S[1]);
            int a[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                String s[] = read.readLine().split(" ");
                for (int j = 0; j < M; j++) a[i][j] = Integer.parseInt(s[j]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maximumSumRectangle(N, M, a));
        }
    }
}
// } Driver Code Ends

class Solution {
    int kadanes(int sum[]){
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        for(int i=0;i<sum.length;i++){
            currSum += sum[i];
            maxSum = Math.max(maxSum, currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
    int maximumSumRectangle(int row, int col, int input[][]) {
        int maxSum = Integer.MIN_VALUE;
        int sum[] = new int[row];
        for(int cStart=0;cStart<col;cStart++){
            Arrays.fill(sum, 0);
            for(int cEnd=cStart; cEnd<col;cEnd++){
                for(int i=0;i<row;i++){
                    sum[i] += input[i][cEnd];
                }
                int currMaxSum = kadanes(sum);
                maxSum = Math.max(maxSum, currMaxSum);
            }
        }
        return maxSum;
    }
};