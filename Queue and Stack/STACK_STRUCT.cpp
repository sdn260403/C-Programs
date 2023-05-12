#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int *a;
	int top;
	int l;
}s;
void push();
void pop();
void disp();

int main()
{
	int ch;
	s.top=-1;
	printf("Enter length of stack ");
	scanf("%d",&s.l);
	s.a=(int*)malloc(sizeof(int)*s.l);
	s.l-=1;
	
	printf("\n1 to push\n2 to pop\n3 to display\n4 to exit");
	do
	{
			printf("\nEnter Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			
			case 2:pop();
			break;
			
			case 3:disp();
			break;
			
		}
	}while(ch!=4);
}
void push()
{
	if(s.top==s.l)
		printf("STACK IS FULL");
	else
	{
		printf("Enter element ");
	s.top+=1;
	scanf("%d",&s.a[s.top]);
	}
}
void pop()
{
	if(s.top==-1)
		printf("STACK IS EMPTY");
		else
		{

	printf("POPPED ITEM IS :- %d",s.a[s.top]);
	s.top-=1;
}
}
void disp()
{
	int i=s.top;
	if(s.top==-1)
	{
		printf("STACK IS EMPTY");
	}
	else
	while(i>=0)
	{
		printf("%3d",s.a[i]);
		i-=1;
	}
}

