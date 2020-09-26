import java.io.*;
import java.util.*;
class Linear
{
    public static int search(int arr[], int x) 
        { 
            int n = arr.length; 
            for(int i = 0; i < n; i++) 
            { 
                if(arr[i] == x) 
                    return i; 
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
                int result = search(arr, x); 
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
            System.out.println("Enter element to be searched:");
            int x=sc.nextInt();
            int result = search(arr, x); 
             if(result == -1) 
                 System.out.print("Element is not present in array"); 
             else
                 System.out.print("Element is present at index " + result);  
            
        }
    }
}