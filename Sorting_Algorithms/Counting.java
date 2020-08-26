class Count
{
    void sort(int arr[])
    {
        int n=arr.length;
        //this new array will hold th sorted array
        int new_arr[]=new int[n];
        int count[] = new int[50]; 
        for (int i=0; i<50; ++i) 
        //array to store the count of elements
            count[i] = 0; 
        //store the count of individual elements
        for(int i=0;i<n;i++)
        {
            ++count[arr[i]];
        }
        for(int i=1;i<=49;i++)
        {
            count[i]+=count[i-1];
            //assigning actual positions in output array
        }
        for(int i=n-1;i>=0;i--)
        {
            new_arr[count[arr[i]]-1]=arr[i];
            --count[arr[i]];
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=new_arr[i];
        }
    }
    public static void main(String args[]) 
    {
        int arr[]={1,4,7,2,9,10,49,16,12,35};
        int l=arr.length;
        Count m=new Count();
        m.sort(arr);
        System.out.println("Sorted array");
        for(int i=0;i<l;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}