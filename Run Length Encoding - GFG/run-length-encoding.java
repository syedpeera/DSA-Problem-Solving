//{ Driver Code Starts
import java.util.*;
 
class RLEncoding
{
   public static void main(String[] args) 
   {
 
      Scanner sc = new Scanner(System.in);
    
	  int T = sc.nextInt();
	  sc.nextLine();
	  while(T>0)
	  {
		  
		String str = sc.nextLine();
		
		GfG g = new GfG();
		System.out.println(g.encode(str));
		
      
        T--;
	  }
   }
}


// } Driver Code Ends


class GfG
{
	String encode(String str)
	{
        int n = str.length();
        if(n == 0){
            return "";
        }
        
        int count = 1;
        StringBuilder result = new StringBuilder();
        for(int i=1; i<=n; i++){
            if(i == n || str.charAt(i) != str.charAt(i-1)){
                result.append(str.charAt(i-1)).append(count);
                count = 1;
            }
            else{
                count++;
            }
        }
        return result.toString();
	}
}