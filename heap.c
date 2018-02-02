 #include<stdio.h>
void heapify(int arr[20],int n,int i)
{
    int l=i*2+1;
    int r=i*2+2;
    int largest=i;
    if(arr[l]>=arr[largest]&&l<n) largest=l;
    if(arr[r]>=arr[largest]&&r<n) largest=r;
    if(largest!=i)
    {
         int temp=arr[largest];
          arr[largest]=arr[i];
          arr[i]=temp;
          heapify(arr,n,largest);
    }
}
void maxheap(int a[20],int n)
{int i;
  for(i=(n/2)-1;i>=0;i--)
        heapify(a,n,i);
}
/*void heapsort(int a[20],int n)
  {int i;
  for(i=(n/2)-1;i>=0;i--)
        heapify(a,n,i);
    while(n>0)
    {
      int temp=a[0];
          a[0]=a[n-1];
          a[n-1]=temp;
      n--;
      maxheap(a,n);
    }
}*/
int main()
{
    int k;int t;int n;
    scanf("%d",&n);
    int arr[n],b[n];
    int i,s=n;
    for(i=0;i<n;++i)
        scanf("%d",&arr[i]);
   maxheap(arr,n);
     for(i=0;i<n;++i)
        printf("%d ",arr[i]);
        return 0;
}
