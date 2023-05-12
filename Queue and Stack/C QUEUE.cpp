#include <stdio.h>
#include <stdlib.h>
struct cq
{
	int front;
	int rear;
	int *a;
	int n;
}q;
void pop();
void push();
void disp();
int main()
{
	int ch,z;
	q.rear=-1;
	q.front=-1;
	printf("ENTER LENGTH OF QUEUE ");
	scanf("%d",&q.n);
	q.a=(int*)malloc(sizeof(int)*q.n);
	printf("\nENTER 0 TO EXIT\nENTER 1 TO PUSH ELEMENT\nENTER 2 TO DELETE ELEMENT\nENTER 3 TO DISPLAY\n");
	do
	{
		printf("\nENTER CHOICE \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				   break;
			case 2:pop();
				   break;
			case 3:disp();
			       break;
			case 0:break;
			default:printf("WRONG INPUT");
		}
	}while(ch!=0);
}
void push()
{
	if((q.rear + 1) % q.n == q.front)
		printf("QUEUE IS FULL\n");
	else
	{
	if (q.front == -1) 
		q.front = 0;
	q.rear=(q.rear+1)%q.n;
	printf("Enter element:\n");
	scanf("%d",&q.a[q.rear]);
	}
}
void pop()
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
      q.front = (q.front + 1) % q.n;
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
	while(q.a[q.rear]!=q.a[i])
	{
		printf("%d ",q.a[i]);
		i=(i+1)%q.n;
	}
	printf("%d ",q.a[i]);
	}
}

