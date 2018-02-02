#include<stdio.h>
#include<stdlib.h>
long long int n;
int binarysearch(long long int *a,long long int k,long long int l,long long int h)
{long long int mid;
  while(l<=h)
  {
    mid=(l+h)/2;
    if(a[mid]==k)
     return mid;
    else if(a[mid]<k)
     l=mid+1;
    else if(a[mid]>k)
     h=mid-1;
  }
 return -1;
}
int main()
{
  long long int p;
  long long int i,t,r=0,j=0;
  scanf("%lld",&n);
  long long int arr[n];
long long int l=1,k;
  for(i=0;i<n;i++)
  {
   scanf("%lld",&arr[i]);
 if(arr[i]<l)k=i;
 l=arr[i];
  }
  scanf("%lld",&t);
  //printf("%lld ",k);
  if(t>=arr[0])
  p=binarysearch(arr,t,0,k-1);
  else
  p=binarysearch(arr,t,k,n-1);
printf("%lld ",p);
  return 0;
}
