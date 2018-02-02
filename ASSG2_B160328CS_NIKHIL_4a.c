#include<stdio.h>
long long int m,n;
long long int check(long long int a[m][n],long long int k,long long int l,long long int h)
{
  while(l<m && h>=0)
  {
     if(a[l][h]==k)
     return 1;
     else if(a[l][h]<k)
     l++;
     else if(a[l][h]>k)
     h--;
  }
  return -1;
}
int main()
{
  long long int k,i,j;
  scanf("%lld %lld",&m,&n);
  long long int arr[m][n];
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
     scanf("%lld",&arr[i][j]);
  scanf("%lld",&k);
  long long int p=check(arr,k,0,n-1);
  printf("%lld ",p);
return 0;
}
