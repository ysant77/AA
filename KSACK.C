#include<stdio.h>
#include<conio.h>
typedef struct ksack
{
   float p,w;
}ksack;
void init(ksack a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter profit and weight for item: %d\n",i+1);
    scanf("%d%d",&a[i].p,&a[i].w);
  }
}
void sort(ksack a[],int n)
{
   int i,j,t;
   for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-1;j++)
     {
       if(a[j].p < a[j+1].p)
       {
	  t=a[j+1].p;
	  a[j+1].p=a[j].p;
	  a[j].p=t;

	  t=a[j+1].w;
	  a[j+1].w=a[j].w;
	  a[j].w=t;
       }
     }
   }
}
float finalprofit(ksack a[],int n,int cap)
{
  float profit=0;
  int c=0,i;
  for(i=0;i<n;i++)
  {
     int w=a[i].w;
     if(c+w <= cap)
     {
       profit+=a[i].p;
       c+=w;
       printf("profit %d\t weight %d\n",a[i].p,a[i].w);
     }
     else if(c < cap)
     {
       profit+=(a[i].p/a[i].w)*(cap-c);
       printf("profit %d\t weight %d\n",a[i].p,cap-c);
       break;
     }
  }
  return profit;
}
void main()
{
  ksack a[20];
  float profit;
  int n,c;
  clrscr();
  printf("Enter number of Objects:\n");
  scanf("%d",&n);
  printf("Enter capacity of sacks:\n");
  scanf("%d",&c);
  init(a,n);
  sort(a,n);
  profit=finalprofit(a,n,c);
  printf("Profit=%f\n",profit);
  getch();
}