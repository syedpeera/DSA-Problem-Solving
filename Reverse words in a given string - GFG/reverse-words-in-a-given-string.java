//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.reverseWords(s));
            t--;
        }
    }
}

// } Driver Code Ends



class Solution 
{
    void reverse(StringBuilder sb, int left, int right){
        while(left<=right){
            char temp = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, temp);
            left++;
            right--;
        }
    }
    String reverseWords(String s)
    {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        int n = s.length();
        int start = 0;
        for(int i=0;i<n;i++){
            if(sb.charAt(i)=='.'){
                reverse(sb, start, i-1);
                start = i+1;
            }
        }
        reverse(sb, start, n-1);
        return sb.toString();
    }
}