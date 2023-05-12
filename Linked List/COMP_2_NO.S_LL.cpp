#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};
struct node* input(int,struct node**);
void add(struct node**,int);
void compare(struct node*,struct node*);
int main()
{
	int i,j;
	struct node *p,*q;
	p=NULL;
	q=NULL;
	printf("ENTER 2 NUMBERS: \n");
	scanf("%d%d",&i,&j);
	p=input(i,&p);
	q=input(j,&q);
	compare(p,q);
}
struct node* input(int x,struct node **q)
{
	while(x>0)
	{
		add(q,x%10);
		x/=10;
	}
	return *q;
}
void add (struct node **q, int num)
{
	struct node *temp;

	temp = (struct node *) malloc(sizeof (struct node));
 
	temp ->d=num;
	temp ->l = *q;
	*q = temp;
}
void compare(struct node *p,struct node *q)
{
	while(p!=NULL || q!=NULL)
	{
		if(p==NULL && q!=NULL || p!=NULL && q==NULL)
		{
			printf("\nNOT EQUAL");
			exit(0);
		}
		if(p->d != q->d)
		{
			printf("\nNOT EQUAL");
			exit(0);
		}
		p=p->l;
		q=q->l;
		
	}
	printf("\nEQUAL");
}
