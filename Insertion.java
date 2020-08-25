class Insertion
{
    void sort(int arr[])
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
    public static void main(String args[])
    {
        int arr[]={38,27,43,3,9,82,10};
        int l=arr.length;
        Insertion m=new Insertion();
        m.sort(arr);
        System.out.println("Sorted array");
        for(int i=0;i<l;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}