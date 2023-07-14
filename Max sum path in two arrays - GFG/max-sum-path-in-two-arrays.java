//{ Driver Code Starts
import java.util.*;

class ArrPathSum1
{
	// Driver Code
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		while(T>0)
		{
			int m = sc.nextInt();
			int n = sc.nextInt();
			int ar1[] = new int[m];
			int ar2[] = new int[n];
			for(int i=0; i<m; i++)
				ar1[i] = sc.nextInt();
			for(int i=0; i<n; i++)
				ar2[i] = sc.nextInt();
		
		Solution g = new Solution();
		System.out.println(g.maxPathSum(ar1,ar2));
		T--;
		}
	}
}
// } Driver Code Ends


class Solution
{
    int maxPathSum(int nums1[], int nums2[])
    {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int sum1 = 0, sum2 = 0;
        int result = 0;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                sum1 = sum1 + nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]){
                sum2 = sum2 + nums2[j];
                j++;
            }
            else{
                result = result + nums1[i] + Math.max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < n1){
            sum1 = sum1 + nums1[i];
            i++;
        }
        while(j < n2){
            sum2 = sum2 + nums2[j];
            j++;
        }
        result = result + Math.max(sum1, sum2);
        return result;
    }
}