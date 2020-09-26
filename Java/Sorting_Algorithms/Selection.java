class Selection
{
    void selectionSort(int arr[])
    {
        int n=arr.length;
        //move the boundary of unsorted array
        for(int i=0;i<n-1;i++)
        {
            int min_index=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min_index])
                    {
                        min_index=j;
                    }
                }
                //System.out.println(min_index+" "+arr[i]);
                int temp=arr[min_index];
                arr[min_index]=arr[i];
                arr[i]=temp;
           
        }
    }
    public static void main(String args[]) 
    {
        int arr[]={38,27,43,3,9,82,10};
        int l=arr.length;
        Selection m=new Selection();
        m.selectionSort(arr);
        System.out.println("Sorted array");
        for(int i=0;i<l;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}