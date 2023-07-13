//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        //Reading total number of testcases
        int t= sc.nextInt();
        
        while(t-- >0)
        {
            //reading the string
            String st = sc.next();
            
            //calling ispar method of Paranthesis class 
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(new Solution().ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");
        
        }
    }
}
// } Driver Code Ends



class Solution
{
    static boolean ispar(String s)
    {
        int n = s.length();
        Stack<Character> bucket = new Stack<>();
        for(int i=0; i<n; i++){
            if(bucket.isEmpty()){
                bucket.add(s.charAt(i));
            }
            else if(bucket.peek() == '(' && s.charAt(i) == ')' || bucket.peek() == '[' && s.charAt(i) == ']' || bucket.peek() == '{' && s.charAt(i) == '}'){
                bucket.pop();
            }
            else{
                bucket.add(s.charAt(i));
            }
        }
        if(bucket.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }
}
