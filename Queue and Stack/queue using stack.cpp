#include <stdio.h>
#include<stdlib.h>
void push(int*,int);
void pop(int*);
void disp(int*);
int top1=-1,top2=-1,n,c=0;
main()
{
	int *s1,*s2,ch;
	printf("Enter the limit of the Queue\n");
	scanf("%d",&n);
	s1=(int*)malloc(sizeof(int)*n);
	s2=(int*)malloc(sizeof(int)*n);
	printf("\nENTER 0 TO EXIT\nENTER 1 TO PUSH ELEMENT\nENTER 2 TO DELETE ELEMENT\nENTER 3 TO DISPLAY\n");
	do
	{
	printf("ENTER CHOICE\n");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element:\n");
				   push(s1,scanf("%d"));
				   break;
			case 2:	while(top1>=0)
					{top2+=1;top1-=1;
					 s2[top2]=s1[top1];
					 }
				     pop(s2);
				     c+=1;top1+=c; 
				   	while(top2>=0)
				   	{top1+=1;top2-=1;
					s1[top1]=s2[top2];	
					}
				   break;
			case 3:disp(s1);
			       break;
			case 0:exit(0);
			default:printf("WRONG INPUT");
		}
	}while(true);
}
void push(int *x,int y)
{
	if(top1==n-1)
		printf("QUEUE IS FULL");
	else
	{
	top1+=1;
	*(x+top1)=y;
	}
}
void pop(int *x)
{
	if(top2==-1)
		printf("QUEUE IS EMPTY");
		else
		{

	printf("POPPED ITEM IS :-%d",*(x+top2));
		top2-=1;
}
}
void disp(int *x)
{
	int i;
	if(top1==-1)
	{
		printf("QUEUE IS EMPTY");
	}
	else
	for(i=c-1;i<=top1;i++)
	{
		printf("%d",*(x+i));
	}
}

