import java.io.*;
import java.util.*;
class Binary
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
    public static int search(int arr[], int l,int r,int x) 
        { 
            if(r>=l)
            {
                int mid=l+(r-l)/2;
                if(arr[mid]==x)
                {
                    return mid;
                }
                if(arr[mid]<x)
                {
                    return search(arr,mid+1,r,x);
                }
                if(arr[mid]>x)
                {
                    return search(arr,l,mid-1,x);
                }
            }
            return -1;
        } 
    public static void main(String args[])
    {
        int arr[]=new int[100];
        if(args[0]!=null)
        {
            try 
            {
                Scanner scanner = new Scanner(new File(args[0]));
                int i = 0;
                while(scanner.hasNextInt())
                {
                arr[i++] = scanner.nextInt();
                } 
                System.out.println("Enter element to be searched:");
                Scanner sc=new Scanner(System.in);
                int x=sc.nextInt();
                sort(arr);
                int result = search(arr, 0,arr.length-1,x); 
                if(result == -1) 
                    System.out.print("Element is not present in array"); 
                else
                    System.out.print("Element is present at index " + result);  
                
            } catch (Exception e) 
            {
                System.out.println("File Not Found");
            }
            
        }
        else
        {
            Scanner sc=new Scanner(System.in);
            System.out.println("Enter number of elements:");
            int n=sc.nextInt();
            int arr2[]=new int[n];
            sort(arr2);
            System.out.println("Enter element to be searched:");
            int x=sc.nextInt();
            int result = search(arr,0,n-1, x); 
             if(result == -1) 
                 System.out.print("Element is not present in array"); 
             else
                 System.out.print("Element is present at index " + result);  
            
        }
    }
}