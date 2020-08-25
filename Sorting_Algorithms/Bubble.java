import java.util.Scanner;
class Bubble
{
    void bubblesort(int arr[])
    {
        int i,j,temp;
        boolean swapped=false;
        int n=arr.length;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                swapped=false;
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swapped=true;
                }
            }
            if(swapped==false)
            {
                break;
            }
        }
    }
    public static void main(String args[])
    {
        Bubble b=new Bubble();
        Scanner sc=new Scanner(System.in);
        int arr[]=new int[10];
        for(int i=0;i<10;i++)
        {
            arr[i]=sc.nextInt();
        }
        b.bubblesort(arr);
        System.out.println("Sorted array");
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]);
        }

    }

}