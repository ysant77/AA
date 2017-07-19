#include<stdio.h>
#include<conio.h>
int a[10],link[10];
struct node
{
  int data;
  struct node *next;
}*start;

void printlist(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  printf("\n");
}

void create()
{
  struct node *c, *b;
  int t,n;
  clrscr();
  printf("Enter the no of elements to be inserted: ");
  scanf("%d",&n);
  for(t=0;t<n;t+=2)
  {
    b=(struct node*)malloc(sizeof(struct node));
    b->data=t;
    c=(struct node*)malloc(sizeof(struct node));
    c->data=t+1;
    if(a[t]>a[t+1])
    {
      c=b->next;
      c->next=NULL;
    }
  }
}
int msort(int low,int high,int &p)
{
  int pp,mid;
  if(low<high)
  {
    mid=(low+high)/2;
    q=msort(low,mid,*q);
    r=msort(mid+1,high,*r);
    pp=merge(*q,*r,*p);
  }
  return pp;
}

int merge(int &q,int &r,int &p)
{
  int *i,*j,*k;
  i=q;
  j=r;
  k=0;
  while((i!=0)&&(j!=0))
  {
    if(a[i]<=a[j])
    {
      link[k]=i;
      k=i;
      i=link[i];
    }
    else
    {
      link[k]=j;
      k=j;
      j=link[j];
    }
  }
  if(i==0)
    link[k]=j;
  else
    link[k]=i;
  p=link[0];
  return p;
}

void main()
{
  int i,n,low, high,*p1,*p;
  clrscr();
  printf("Enter n: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    printf("\nEnter element %d: ",i);
    scanf("%d",&a[i]);
  }
  low=1;
  high=n;
  printf("\nLink : \n");
  for(i=0;i<=n;i++)
  {
    link[i]=0;
    printf("%d  ",link[i]);
  }
  printf("\n\nUnsorted list : \n");
  for(i=1;i<=n;i++)
    printf("%d  ",a[i]);
  printf("\n\n");
  *p1=msort(low,high,*p);
  printf("sorted list: \n");
    printlist(p1);
  getch();
}