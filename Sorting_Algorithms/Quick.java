class Quick
{
   int partition(int arr[],int low,int high)
   {
       int pivot=arr[high];
       int i=low-1;//setting initial index
       for(int j=low;j<high;j++)
       {
           if(arr[j]<pivot)
           {
               i++;
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;

           }

       }
       //all elements upto i contain values smaller than pivot
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
   }
    void quicksort(int arr[],int low,int high)
    {
        if(low<high)
        {
            int pi=partition(arr,low,high);
            quicksort(arr,low,pi-1);
            quicksort(arr,pi+1,high);
        }
    }
    public static void main(String args[]) 
    {
        int arr[]={38,27,43,3,9,82,10};
        int l=arr.length;
        Quick m=new Quick();
        m.quicksort(arr,0,l-1);
        System.out.println("Sorted array");
        for(int i=0;i<l;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}