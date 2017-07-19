#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<dos.h>
#define INF 9999
typedef struct edge
{
  int p,c;
  int w;
}edge;
void creategraph(int a[20][20],int N)
{
   int i,j;
   printf("Enter adjacency matrix:\n");
   for(i=0;i<N;i++)
   {
     for(j=0;j<N;j++)
     {
       scanf("%d",&a[i][j]);
       if(a[i][j]==0)
       {
	  a[i][j]=INF;
       }
     }
   }
}
void sortEdges(edge e[],int n)
{
   int i,j;
   edge t;
   for(i=0;i < n-1;i++)
   {
      for(j=0;j< n-1;j++)
      {
	 if(e[j].w > e[j+1].w)
	 {
	    t=e[j];
	    e[j]=e[j+1];
	    e[j+1]=t;
	 }
      }
   }
}
int collectEdges(int a[20][20],edge e[],int N)
{
   int i,j,k=0;
   for(i=0;i < N;i++)
   {
      for(j=i+1;j < N;j++)
      {
	  if(a[i][j]!=INF)
	  {
	     e[k].p=i;
	     e[k].c=j;
	     e[k].w=a[i][j];
	     k++;
	  }
     }
   }
 return k;
}
int kruskal(int a[20][20],int N)
{
  edge e[20];
  int parent[20],cost=0,i;
  int n=collectEdges(a,e,N);
  sortEdges(e,n);
  for(i=0;i < N;i++)
     parent[i]=-1;
  for(i=0;i < N;i++)
  {
     int p=e[i].p;
     int c=e[i].c;
     while(parent[p]!=-1)
     {
	p=parent[p];
     }
     while(parent[c]!=-1)
     {
	c=parent[c];
     }
     if(p!=c)
     {
	parent[c]=p;
	cost+=e[i].w;
	printf(" %c\t%c\n",e[i].p+65,e[i].c+65);

	c++;
     }
  }
  return cost;
}
void main()
{
   int a[20][20],N;
   int cost;
   clrscr();
   printf("Enter number of vertices:\n");
   scanf("%d",&N);
   creategraph(a,N);
   cost=kruskal(a,N);
   printf("Cost=%d\n",cost);
   getch();
}
