 #include <stdio.h>
#include <stdlib.h>
long int n;
void merge(long int a[n],long int l,long int r,long int s,long int h)
{
    long int left[n],middle[n],right[n];long int x;
    long int t;
    for(t=0;t<n;t++)
    {left[t]=0;right[t]=0;middle[t]=0;}
    for(t=0;t<r-l+1;t++)
    left[t]=a[t+l];
    for(t=0;t<s-r;t++)
    middle[t]=a[t+r+1];
    for(t=0;t<h-s;t++)
    right[t]=a[t+s+1];
    long int i=0,j=0,k=0;
    for(x=l;x<=h;x++)
    {
    if(i<r-l+1 && j<s-r && k<h-s)
    {
        if(left[i]<=middle[j] && left[i]<=right[k])
        {a[x]=left[i];i++;}
        else if(middle[j]<=left[i] && middle[j]<=right[k])
        {a[x]=middle[j];j++;}
        else if(right[k]<=middle[j] && right[k]<=left[i])
        {a[x]=right[k];k++;}
    }
    else if(i<r-l+1 && j<s-r)
    {
        if(left[i]<=middle[j])
        {a[x]=left[i];i++;}
        else
        {a[x]=middle[j];j++;}
    }
    else if(i<r-l+1 && k<h-s)
    {
        if(left[i]<=right[k])
        {a[x]=left[i];i++;}
        else
        {a[x]=right[k];k++;}
    }
    else if(k<h-s && j<s-r)
    {
        if(right[k]<middle[j])
        {a[x]=right[k];k++;}
        else
        {a[x]=middle[j];j++;}
    }
    else if(i<r-l+1)
        {a[x]=left[i];i++;}
    else if(j<s-r)
        {a[x]=middle[j];j++;}
    else if(k<h-s)
        {a[x]=right[k];k++;}
    }
}
void mergesort(long int a[n],long int l,long int h)
{long int r,s;

    if(h-l+1==2)
    { merge(a,l,l,h,h);}
    if(h-l+1==3)
    {merge(a,l,l+1,h,h);}
    if(h-l+1>=3)
    {
    if((h-l+1)%3==0)
    {
        r=l+((h-l+1)/3) -1;
        s=l+(2*(h-l+1)/3) -1;
    }
    if((h-l+1)%3==1)
    {
        r=l+(h-l+1)/3;
        s=l+2*(h-l+1)/3;
    }
    if((h-l+1)%3==2)
    {
        r=l+(h-l+1)/3;
        s=l+2*(h-l+1)/3;
    }
    mergesort(a,l,r);
    mergesort(a,r+1,s);
    mergesort(a,s+1,h);
    merge(a,l,r,s,h);
    }
}
int main()
{
    FILE *fin,*fout;
     long int *arr=malloc(sizeof(long int));
    fin=fopen("in","rb");
    if(fin==NULL)
    {printf("ERROR");exit(0);}
    fout=fopen("out","wb");
    n=1;long int i=0;
    while(1)
    {
        arr=(long int *)realloc(arr,sizeof(long int)*n);
        fscanf(fin,"%ld",&arr[i]);
        if(feof(fin)) break;
        n++;i++;
    }
    long int x=n-1;
    mergesort(arr,0,x-1);
    for(i=0;i<x;i++)
        fprintf(fout,"%ld ",arr[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}

