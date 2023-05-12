#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};
struct node *p;
void push(int);
void pop();
void disp(struct node*);
int main()
{
	int z,ch,n;
	p=NULL;
	printf("\n1 to push\n2 to pop\n3 to display\n4 to exit");
	do
	{
		printf("\nEnter Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter Value\n");
				   scanf("%d",&z);
			       push(z);
			break;
			
			case 2:pop();
			break;
			
			case 3:disp(p);
			break;
			
		}
	}while(ch!=4);
}
void push(int y)
{
	struct node *r;
	if(p==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node*));
		p->d=y;
		p->l=NULL;
	}
	else
	{
		r=(struct node*)malloc(sizeof(struct node*));
		r->d=y;
		r->l=p;
		p=r;	
	}	
}
void pop()
{
	if(p==NULL)
	{
		printf("STACK IS EMPTY");
	}
	else
	{
	struct node *temp=p;
	p=p->l;
	printf("DATA DELETED : %d",temp->d);
	free(temp);
	}
}
void disp(struct node *x)
{
	printf ("\n");
   if (x == NULL)
   {
   	printf("STACK is empty");
      return;
   }
	while (x != NULL)
	{
		printf ("%d ", x->d);
		x = x->l;
	}
}
