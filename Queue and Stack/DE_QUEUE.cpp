#include<stdio.h>
#include<stdlib.h>
int front;
int rear;
int *a;
int n;
void del_f();
void del_r();
void insert_f();
void insert_r();
void disp();
int main()
{
	int c,ch,z;
	rear=-1;
	front=-1;
	printf("ENTER LENGTH OF QUEUE ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	printf("MENU TO RESTRICT:\n");
	printf("\nENTER 1 TO RESTRICT INSERT ELEMENT FROM FRONT\nENTER 2 TO RESTRICT DELETE ELEMENT FROM FRONT\nENTER 3 TO RESTRICT INSERT ELEMENT FROM REAR\nENTER 4 TO RESTRICT DELETE ELEMENT FROM REAR\n");
	printf("\nENTER CHOICE \n");
		scanf("%d",&c);
	switch(c)
	{
		case 1:	printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT FROM FRONT\nENTER 3 TO DELETE ELEMENT FROM REAR\nENTER 4 TO DISPLAY ELEMENTS\n");
				do
				{
					printf("\nENTER CHOICE \n");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:insert_r();
				   				break;
						case 2:del_f();
				   				break;
						case 3:del_r();
								break;
						case 4:disp();
			       				break;
						case 0:break;
						default:printf("WRONG INPUT");
					}
				}while(ch!=0);
				break;
		case 2:	printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT FROM REAR\nENTER 3 TO INSERT ELEMENT FROM FRONT\nENTER 4 TO DISPLAY ELEMENTS\n");
				do
				{
					printf("\nENTER CHOICE \n");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:insert_r();
				   				break;
						case 2:del_r();
				   				break;
						case 3:insert_f();
								break;
						case 4:disp();
			       				break;
						case 0:break;
						default:printf("WRONG INPUT");
					}
				}while(ch!=0);
				break;
		case 3:	printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM FRONT\nENTER 2 TO DELETE ELEMENT FROM FRONT\nENTER 3 TO DELETE ELEMENT FROM REAR\nENTER 4 TO DISPLAY ELEMENTS\n");
				do
				{
					printf("\nENTER CHOICE \n");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:insert_f();
				   				break;
						case 2:del_f();
				   				break;
						case 3:del_r();
								break;
						case 4:disp();
			       				break;
						case 0:break;
						default:printf("WRONG INPUT");
					}
				}while(ch!=0);
				break;
		case 4:	printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT\nENTER 3 TO INSERT ELEMENT FROM FRONT\nENTER 4 TO DISPLAY ELEMENTS\n");
				do
				{
					printf("\nENTER CHOICE \n");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:insert_r();
				   				break;
						case 2:del_f();
				   				break;
						case 3:insert_f();
								break;
						case 4:disp();
			       				break;
						case 0:break;
						default:printf("WRONG INPUT");
					}
				}while(ch!=0);
				break;
	}
}
void insert_r()
{
	int i,k;
	if(front==0 && rear == n-1)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	if (front == -1) 
		front = 0;
	if(rear==n-1 && front!=0)
	{
		for(i=front-1;i<rear;i++)
			a[i]=a[i+1];
		front-=1;
	}
	else
		rear+=1;
	printf("Enter element:\n");
	scanf("%d",&k);
	a[rear]=k;
}

void insert_f()
{
	int i,k;
	if(front==0 && rear == n-1)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	if (front == -1) 
		front = 0;
	if(rear!=n-1 && front==0)
	{
		for(i=rear+1;i>front;i--)
			a[i]=a[i-1];
		rear+=1;
	}
	else
		front-=1;
	printf("Enter element:\n");
	scanf("%d",&k);
	a[front]=k;
}

void del_f()
{
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
	printf("POPPED ITEM IS :- %d",a[front]);
	if (front == rear) 
      front=rear = -1;
    else
      front+=1;
	}
}

void del_r()
{
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
	printf("POPPED ITEM IS :- %d",a[rear]);
	if (front == rear) 
      front=rear = -1;
    else
      rear-=1;
	}
}

void disp()
{
	int i;
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else
	{
	i=front;
	while(i<=rear)
	{
		printf("%d ",a[i]);
		i+=1;
	}
	}
}
