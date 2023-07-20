//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
	        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            long a[] = new long[(int)(n)];
            // long getAnswer[] = new long[(int)(n)];
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(inputLine[i]);
            }
            int k = Integer.parseInt(br.readLine().trim());
            
            Compute obj = new Compute();
            long answer[] = obj.printFirstNegativeInteger(a, n, k);
            int sz = answer.length;
            
            StringBuilder output = new StringBuilder();
            for(int i=0;i<sz;i++)
                output.append(answer[i]+" ");
            System.out.println(output);
            
        }
	}
}


// } Driver Code Ends

class Compute {
    
    public long[] printFirstNegativeInteger(long nums[], int n, int k)
    {
        long result[] = new long[n-k+1];
        Queue<Long> q = new LinkedList<>();
        int j=0;
        for(int i=0; i<k; i++){
            if(nums[i] < 0){
                q.add(nums[i]);
            }
        }
        if(q.isEmpty()){
            result[j++] = 0;
        }
        else{
            result[j++] = q.peek();
        }
        for(int i=k; i<n; i++){
            if(nums[i] < 0){
                q.add(nums[i]);
            }
            if(nums[i-k] < 0){
                q.poll();
            }
            if(q.isEmpty()){
                result[j++] = 0;
            }
            else{
                result[j++] = q.peek();
            }
        }
        return result;
    }
}