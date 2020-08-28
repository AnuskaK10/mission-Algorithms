class Interpol
{
    public static int search(int arr[],int x)
    {
        int lo=0;
        int hi=arr.length-1;
        while(lo<=hi && arr[lo]<=x && x<=arr[hi])
        {
            if(lo==hi)
            {
                if(arr[lo]==x)
                    return x;
                else
                    return -1;
            }
            int pos=lo+(((x-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]));
            if(arr[pos]==x)
            {
                return pos;
            }
            if(arr[pos]<x)
            {
                lo=pos+1;
            }
            else{
                hi=pos-1;
            }
        }
        return -1;
    }
    public static void main(String[] args) 
	{ 
		int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 
            24, 33, 35, 42, 47}; 
		
		int x = 18; 
		System.out.print ("Found at index: "+ 
				search(arr, x)); 
	} 
}