//{ Driver Code Starts
//Initial Template for Java

import java.util.*;

public class GFG
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) 
        {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            int n3 = sc.nextInt();
            
            int A[] = new int[n1];
            int B[] = new int[n2];
            int C[] = new int[n3];
            
            for (int i = 0;i < n1;i++)
            {
                A[i] = sc.nextInt();
            }
            for (int i = 0;i < n2;i++)
            {
                B[i] = sc.nextInt();
            }
            for (int i = 0;i < n3;i++)
            {
                C[i] = sc.nextInt();
            }
            
            Solution sol = new Solution();
            ArrayList<Integer> res = sol.commonElements(A, B, C, n1, n2, n3);
            if (res.size() == 0)
            {
                System.out.print(-1);
            }
            else 
            {
                for (int i = 0;i < res.size();i++)
                {
                    System.out.print(res.get(i) + " ");
                }    
            }
            System.out.println();
        }
    }
}


// } Driver Code Ends


class Solution
{
    ArrayList<Integer> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) 
    {
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n1 && j < n2 && k < n3){
            if(A[i] == B[j] && B[j] == C[k]){
                if(result.isEmpty() || result.get(result.size()-1) != A[i]){
                    result.add(A[i]);
                }
                i++;
                j++;
                k++;
            }
            else if(A[i] <= B[j] && A[i] <= C[k]){
                i++;
            }
            else if(B[j] <= A[i] && B[j] <= C[k]){
                j++;
            }
            else{
                k++;
            }
        }
        return result;
    }
}