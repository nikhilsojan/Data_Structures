#include<stdio.h>
#include<stdlib.h>
long long int n;
void heapify(long long int arr[n],long long int i)
{
    long long int l=i*2+1;
    long long int r=i*2+2;
    long long int largest=i;
    if(arr[l]>arr[largest]&&l<n) largest=l;
    if(arr[r]>arr[largest]&&r<n) largest=r;
    if(largest!=i)
    {
        long long int temp=arr[largest];
          arr[largest]=arr[i];
          arr[i]=temp;
          heapify(arr,largest);
    }
}

long long int findlargest(long long int a[n],long long int k)
{long long int i;
    for(i=(n/2)-1;i>=0;i--)
        heapify(a,i);
  while(k>0)
    {
      a[0]=a[n-1];
      n--;k--;
      heapify(a,0);
    }
    return a[k];
}
int main()
{
    long long int k;long long int t;
    scanf("%lld",&n);
    long long int arr[n],b[n];
    long long int i,s=n;
    for(i=0;i<n;++i)
        scanf("%lld",&arr[i]);
       scanf("%lld",&k);
       if(k>n)
       {
           printf("error");exit(0);
       }
    t=findlargest(arr,k-1);
        printf("%lld ",t);
        return 0;
}
