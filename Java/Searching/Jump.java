import java.io.*;
import java.util.*;
class Jump
{
    static void sort(int arr[])
    {
        int n=arr.length;
        for(int i=1;i<n;i++)
        {
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                //move elements greater than key to one space ahead to make space for key
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
    public static int search(int arr[],int x) 
        { 
            int n = arr.length; 
        int step = (int)Math.floor(Math.sqrt(n)); 
        int prev = 0; 
        while (arr[Math.min(step, n)-1] < x) 
        { 
            prev = step; 
            step += (int)Math.floor(Math.sqrt(n)); 
            if (prev >= n) 
                return -1; 
        } 
        while (arr[prev] < x) 
          { 
            prev++; 
            if (prev == Math.min(step, n)) 
                return -1; 
        } 
        if (arr[prev] == x) 
            return prev; 
         return -1; 
        } 
    public static void main(String args[])
    {
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter number of elements:");
            int n=sc.nextInt();
            int arr2[]=new int[n];
            for(int i=0;i<n;i++)
            {
                arr2[i]=sc.nextInt();
            }
            sort(arr2);
            System.out.println("Enter element to be searched:");
            int x=sc.nextInt();
            int result = search(arr2, x); 
             if(result == -1) 
                 System.out.print("Element is not present in array"); 
             else
                 System.out.print("Element is present at index " + result);  
            
        
    }
}