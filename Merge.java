class Merge
{
    void merge(int arr[],int l,int m,int r)
    {
      int i,j,k;
      int n1=(m-l)+1;int n2=r-m;
      //making temporary arrays
      int L[]=new int[n1];
      int R[]=new int[n2];
      //copying data to temporary arrays
      for(i=0;i<n1;i++)
      {
        L[i]=arr[l+i];
      }
      for(j=0;j<n2;j++)
      {
          R[j]=arr[m+1+j];
      }
      i=0;j=0;k=l;
      while(i<n1 && j<n2)
      {
          if(L[i]<R[j])
          {
              arr[k]=L[i];
              i++;
          }
          else
          {
              arr[k]=R[j];
              j++;
          }
          k++;
      }
      //remaining elements
      while(i<n1)
      {
          arr[k]=L[i];
          i++;
          k++;
      }
      while(j<n2)
      {
          arr[k]=R[j];
          j++;
          k++;
      }
    }
    void mergesort(int arr[],int l,int r)
    {
       if(l<r)
       {
           int m=(l+(r-1))/2;
           mergesort(arr,l,m);
           mergesort(arr,m+1,r);
           merge(arr,l,m,r);
       }
    }
    public static void main(String args[]) 
    {
        int arr[]={38,27,43,3,9,82,10};
        int l=arr.length;
        Merge m=new Merge();
        m.mergesort(arr,0,l-1);
        System.out.println("Sorted array");
        for(int i=0;i<l;i++)
        {
            System.out.print(" "+arr[i]);
        }
    }
}