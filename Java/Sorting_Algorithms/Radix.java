class Radix
{
    int getMax(int arr[], int n) 
    { 
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx; 
    } 
    void countsort(int arr[],int n,int exp)
    {
        //this new array will hold th sorted array
        int new_arr[]=new int[n];
        int count[] = new int[50]; 
        for (int i=0; i<50; ++i) 
        //array to store the count of elements
            count[i] = 0; 
        //store the count of individual elements
        for(int i=0;i<n;i++)
        {
            ++count[(arr[i]/exp)%10];
        }
        for(int i=1;i<=49;i++)
        {
            count[i]+=count[i-1];
            //assigning actual positions in output array
        }
        for(int i=n-1;i>=0;i--)
        {
            new_arr[count[(arr[i]/exp)%10]-1]=arr[i];
            --count[(arr[i]/exp)%10];
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=new_arr[i];
        }
    }
    void radixsort(int arr[],int n)
    {
        int m=getMax(arr,n);
        for(int exp=1;m/exp>0;exp*=10)
        {
            countsort(arr,n,exp);
        }
    }
    void print(int arr[], int n) 
    { 
        for (int i=0; i<n; i++) 
            System.out.print(arr[i]+" "); 
    } 
    public static void main (String[] args) 
    { 
        Radix r=new Radix();
        int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
        int n = arr.length; 
        r.radixsort(arr, n); 
        r.print(arr, n); 
    } 
}