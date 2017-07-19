#include<stdio.h>
#include<conio.h>
#define INF 9999
void creategraph(int a[30][30],int n)
{
   int i,j;
   printf("Enter the cost matrix:\n");
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
	scanf("%d",&a[i][j]);
	if(a[i][j]==0)
	{
	  a[i][j]=INF;
	}
     }
   }
}
int minNode(int dist[],int visited[],int n)
{
  int min=INF,m=0,i;
  for(i=0;i<n;i++)
  {
    if(!visited[i] && dist[i]<min)
    {
       min=dist[i];
       m=i;
    }
  }
  return m;
}
int prim(int a[][30],int start,int prev[],int n)
{
  int sum=0,i,j,d;
  int dist[20],visited[20];
  for(i=0;i<n;i++)
     visited[i]=INF;
  dist[start]=0;
  visited[start]=1;
  for(j=1;j<n;j++)
  {
    for(i=0;i<n;i++)
    {
       d=a[start][i];
       if(!visited[i] && d<dist[i])
       {
	 dist[i]=d;
	 prev[i]=start;
       }
    }
    start=minNode(dist,visited,n);
    sum+=dist[start];
    visited[start]=1;
  }
 return sum;
}
void main()
{
  int i,a[30][30],prev[30],mincost,n;
  clrscr();
  printf("Enter number of nodes:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
     prev[i]=-1;
  creategraph(a,n);
  mincost=prim(a,0,prev,n);
  printf("Mincost=%d\n",mincost);
  printf("Selected edges:\n");
  for(i=0;i<n;i++)
     printf("%c\t %c\n",i+65,prev[i]+65);
  getch();
}
