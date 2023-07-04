//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            List<String> ans = obj.find_permutation(S);
            for( int i = 0; i < ans.size(); i++)
            {
                out.print(ans.get(i)+" ");
            }
            out.println();
                        
        }
        out.close();
	}
}


// } Driver Code Ends


class Solution {
    public void swap(char arr[], int i, int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public void permutation(char arr[], List<String> result, int l, int r){
        if(l==r){
            result.add(String.valueOf(arr));
        }
        else{
            for(int i=l;i<=r;i++){
                boolean shouldSwap = true;
                for(int j=l;j<i;j++){
                    if(arr[j]==arr[i]){
                        shouldSwap = false;
                        break;
                    }
                }
                if(shouldSwap){
                    swap(arr, l, i);
                    permutation(arr, result, l+1, r);
                    swap(arr, l, i);
                }
            }
        }
    }
    public List<String> find_permutation(String s) {
        List<String> result = new ArrayList<>();
        permutation(s.toCharArray(), result, 0, s.length()-1);
        Collections.sort(result);
        return result;
    }
}