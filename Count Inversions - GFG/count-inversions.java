//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Sorting
{
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            
            for(long i = 0; i < n; i++)
             arr[(int)i] = sc.nextLong();
             
            System.out.println(new Solution().inversionCount(arr, n));
            
        }
    }
}

// } Driver Code Ends

class Solution {
    static long merge(long arr[], long left, long mid, long right) {
        long merged[] = new long[(int) (right - left + 1)];
        long index1 = left;
        long index2 = mid + 1;
        long x = 0;
        long countInversions = 0;

        while (index1 <= mid && index2 <= right) {
            if (arr[(int) index1] <= arr[(int) index2]) {
                merged[(int) x++] = arr[(int) index1++];
            } else {
                merged[(int) x++] = arr[(int) index2++];
                countInversions += (mid - index1 + 1);
            }
        }

        while (index1 <= mid) {
            merged[(int) x++] = arr[(int) index1++];
        }

        while (index2 <= right) {
            merged[(int) x++] = arr[(int) index2++];
        }

        for (long i = 0, j = left; i < merged.length; i++, j++) {
            arr[(int) j] = merged[(int) i];
        }

        return countInversions;
    }

    static long mergeSort(long arr[], long left, long right) {
        long countInversions = 0;
        if (left < right) {
            long mid = left + (right - left) / 2;
            countInversions += mergeSort(arr, left, mid);
            countInversions += mergeSort(arr, mid + 1, right);
            countInversions += merge(arr, left, mid, right);
        }
        return countInversions;
    }

    static long inversionCount(long arr[], long n) {
        return mergeSort(arr, 0, n - 1);
    }
}

