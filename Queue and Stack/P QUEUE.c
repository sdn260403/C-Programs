#include<stdio.h>
#include<stdlib.h>
struct pq
{
	int front;
	int rear;
	int *a;
	int n;
}q;
void del();
void insert();
void disp();
int main()
{
	int ch,z;
	q.rear=-1;
	q.front=-1;
	printf("ENTER LENGTH OF QUEUE ");
	scanf("%d",&q.n);
	q.a=(int*)malloc(sizeof(int)*q.n);
	printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT\nENTER 2 TO DELETE ELEMENT\nENTER 3 TO DISPLAY MAX AND MIN ELEMENT\nENTER 4 TO DISPLAY ELEMENTS\n");
	do
	{
		printf("\nENTER CHOICE \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				   break;
			case 2:del();
				   break;
			case 3:if(q.front==-1)
						printf("QUEUE IS EMPTY\n");
					else
						printf("MAX : %d    MIN : %d\n",q.a[q.rear],q.a[q.front]);
					break;
			case 4:disp();
			       break;
			case 0:break;
			default:printf("WRONG INPUT");
		}
	}while(ch!=0);
}
void insert()
{
	int i,k,p;
	if(q.rear == q.n-1)
		printf("QUEUE IS FULL\n");
	else
	{
	if (q.front == -1) 
		q.front = 0;
	q.rear+=1;
	printf("Enter element:\n");
	scanf("%d",&k);
	q.a[q.rear]=k;
	p=q.rear-1;
	while(q.a[p]>k&&p>=0)
		{
			q.a[p+1]=q.a[p];
			p-=1;
	    }
	q.a[p+1]=k;
	}
}
void del()
{
	if(q.front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		printf("POPPED ITEM IS :- %d",q.a[q.front]);
	if (q.front == q.rear) 
	{
      q.front = -1;
      q.rear = -1;
    }
    else
      q.front+=1;
	}
}
void disp()
{
	int i;
	if(q.front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
	i=q.front;
	while(i<=q.rear)
	{
		printf("%d ",q.a[i]);
		i+=1;
	}
	}
}
