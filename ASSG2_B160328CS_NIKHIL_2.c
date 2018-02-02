#include<stdio.h>
#include<stdlib.h>
int y=0;
long int partition1(long int a[],long int l,long int h)
{
long int i=l-1;long int c=l,b=h;long int p=l+rand()%(h-l+1);long int x=a[p],j;
long int temp=a[h];
a[h]=a[p];
a[p]=temp;
for(j=l;j<=h-1;j++)
 {
  if(a[j]<=x)
  {
    i++;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
  }
 }
  temp=a[i+1];
  a[i+1]=a[h];
  a[h]=temp;
  return i+1;
}
long int median(long int a[],long int l,long int h,long int k)
{
  while(l<=h)
  {
    long int p=partition1(a,l,h);
    long int len=p-l+1;
    if(k==len)
    {

    return a[p];

    }
    else if(k<len)
    h=p-1;
    else if(k>len)
    {
    k=k-len;
    l=p+1;
    }
  }
}
long int partition(long int a[],long int l,long int h)
{
 if(l<h)
 {
    long int z;
long int i=l-1;long int c=l,b=h;long int x,j;long int len=h-l+1;
if(len%2==0) z=len/2;
else z=(len/2)+1;
x=median(a,l,h,z);
      if(y<3)
      {
        printf("%ld\n",x);
        y++;
      }
for(j=l;j<=h-1;j++)
 {
  if(a[j]<x)
  {
    i++;
    long int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
  }
 }
  return i+1;
 }
}
long int quicksort(long int a[],long int l,long int h)
{int i;
    if(l<=h)
    {
        long int p=partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}
int main()
{
    long int k,i,j,n;
  scanf("%ld",&n);
  long int arr[n];
  for(i=0;i<n;i++)
     scanf("%ld",&arr[i]);
quicksort(arr,0,n-1);
 for(i=0;i<n;i++)
     printf("%ld ",arr[i]);
     return 0;
}

