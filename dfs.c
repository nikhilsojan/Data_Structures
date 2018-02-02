#include<stdio.h>

int graph[10000][10000],stack[10000],visited[10000],a=0,n,m,v,u,t;

void push(int *s,int x)

{
  
for(int i=a;i>=1;i--)
  
s[i]=s[i-1];
  
s[0]=x;
  
a++;

}


int pop(int *s)

{
  
int flag=s[0];
  
for(int i=0;i<a;i++)
  
s[i]=s[i+1];
  
a--;
  
return flag;

}


int empty(int *s)

{
int flag=1;
  
for(int i=0;i<a;i++)
  
if(s[i]!=0)
{flag=0;break;}
  
return flag;

}


void dfs(int gp[10000][10000],int k)

{

  push(stack,k);visited[k]=1;

  while(!empty(stack))

  {

    k=pop(stack);printf("%d ",k);

    for(int i=1;i<=n;i++)

    if(graph[k][i]==1 && visited[i]==0)

    {

      push(stack,i);visited[i]=1;

    }

  }

}


int main()

{

  scanf("%d %d",&n,&m);

  for(int i=1;i<=n;i++)

   for(int j=1;j<=n;j++)

    graph[i][j]=0;

  for(int j=0;j<m;j++)

  {

    scanf("%d %d",&u,&v);

    graph[u][v]=1;

  }
  scanf("%d",&t);

  dfs(graph,t);

  return 0;

}