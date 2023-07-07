//{ Driver Code Starts
//initial code
import java.util.*;
import java.lang.*;
class InterLeaveString
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0)
        {
            String a =sc.next();
            String b = sc.next();
            String c = sc.next();
            Solution g=new Solution();
        
            System.out.println(g.isInterLeave(a,b,c)==true?1:0);
            t--;
        }
    }
}


// } Driver Code Ends


/*you are required to complete this method */
class Solution {
	public boolean isInterLeave(String a,String b,String c)
	{
        int m = a.length();
        int n = b.length();
        boolean dp[][] = new boolean[m+1][n+1];
        
        if(m+n != c.length()){
            return false;
        }
        
        dp[0][0] = true;
        
        for(int i=1;i<=m;i++){
            if(a.charAt(i-1)==c.charAt(i-1)){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1;j<=n;j++){
            if(b.charAt(j-1)==c.charAt(j-1)){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a.charAt(i-1) == c.charAt(i+j-1)){
                    dp[i][j] = dp[i-1][j];
                }
                if(b.charAt(j-1) == c.charAt(i+j-1)){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
	}
}

