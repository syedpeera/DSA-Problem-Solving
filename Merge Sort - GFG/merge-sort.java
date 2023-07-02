//{ Driver Code Starts
import java.util.*;

class Merge_Sort
{
    //method to print the elements of the array
	static void printArray(int arr[])
    {
        StringBuffer sb=new StringBuffer("");
        int n = arr.length;
        for (int i=0; i<n; ++i)
            sb.append(arr[i]+" ");
        System.out.println(sb.toString());
    }

    

	public static void main(String args[])
	{
	    //taking input using Scanner class
		Scanner sc = new Scanner(System.in);
		
		//taking testcases
		int T = sc.nextInt();
		while(T>0)
		{
		    //taking elements count
			int n = sc.nextInt();
			
			//creating an object of class Merge_Sort
			Merge_Sort ms = new Merge_Sort();
			
			//creating an array of size n
			int arr[] = new int[n];
			
			//adding elements to the array
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();

            
			Solution g = new Solution();
			
			//calling the method mergeSort
			g.mergeSort(arr,0,arr.length-1);

            //calling the method printArray
			ms.printArray(arr);
		T--;
		}
	}
}



// } Driver Code Ends


class Solution
{
    void merge(int arr[], int left, int mid, int right)
    {
        int merged[] = new int[right-left+1];
        int index1 = left;
        int index2 = mid+1;
        int x = 0;
        while(index1 <= mid && index2 <= right){
            if(arr[index1] <= arr[index2]){
                merged[x++] = arr[index1++];
            }
            else{
                merged[x++] = arr[index2++];
            }
        }
        
        while(index1 <= mid){
            merged[x++] = arr[index1++];
        }
        
        while(index2 <= right){
            merged[x++] = arr[index2++];
        }
        
        for(int i=0, j=left;i<merged.length;i++,j++){
            arr[j] = merged[i];
        }
    }
    void mergeSort(int arr[], int left, int right)
    {
        if(left >= right){
            return;
        }
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
