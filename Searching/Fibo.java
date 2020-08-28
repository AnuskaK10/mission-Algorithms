
import java.util.*; 

class Fibonacci 
{ 
	public static int min(int x, int y) 
	{ 
	 return (x <= y)? x : y; 
	} 
	public static int fibMonaccianSearch(int arr[],int x, int n) 
	{ 
		 int fib0=0;
		 int fib1=1;
		 int fibm=fib0+fib1;
		 while(fibm<n)
		 {
			 fib0=fib1;
			 fib1=fibm;
			 fibm=fib0+fib1;
		 }
		 int offset=-1;//number of elements to be eliminated from front
		 while(fibm>1)
		 {
			 int i=min(offset+fib0,n-1);
			 if(arr[i]<x)
			 {
				fibm=fib1;
				fib1=fib0;
				fib0=fibm-fib1;
				offset=i;
			 }
			 else if(arr[i]>x)
			 {
				 fibm=fib0;
				 fib1=fib1-fib0;
				 fib0=fibm-fib1;
			 }
			 else return i;
		 }
		 if(fib1==1 && arr[offset+1]==x)
		 {
			 return offset+1;
		 }
		 return -1;
		 
	}  
public static void main(String[] args) 
	{ 
		int arr[] = {10, 22, 35, 40, 45, 50, 
					80, 82, 85, 90, 100}; 
		int n = arr.length; 
		int x = 85; 
		System.out.print ("Found at index: "+ 
				fibMonaccianSearch(arr, x, n)); 
	} 
} 
