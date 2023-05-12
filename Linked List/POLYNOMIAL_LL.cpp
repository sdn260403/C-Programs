#include<stdio.h>
#include <stdlib.h>
struct node
{
	int d;
	int e;
	struct node *l;
};
void append(struct node **,int,int);
void add(struct node *,struct node *);
struct node * accept(struct node *);
void disp(struct node*);
int main()
{
	struct node *p,*q;
	p=NULL;
	q=NULL;
	p=accept(p);
	q=accept(q);
	add(p,q);
}

struct node * accept(struct node *x)
{
	int i,c1,d,e;
	printf("\nEnter length of Polynomial ");
	scanf("%d",&c1);
	for(i=1;i<=c1;i++)
	{
		printf("ENTER COEFFICIENT AND EXPONENT FOR ELEMENT %d \n",i);
		scanf("%d",&d);
		scanf("%d",&e);
		append(&x,d,e);
	}
	printf("Polynomial accepted :\n");
	disp(x);
	return x;
}
void append (struct node **q, int num,int x)
{
	struct node *temp, *r;
	if (*q == NULL) 			
	{
		temp = (struct node *) malloc (sizeof(struct node));
		temp ->d = num;
		temp->e=x;
		temp ->l = NULL;
		*q = temp;
	}

	else
	{
		temp = *q;
		 while (temp ->l != NULL)
		 temp = temp ->l;
		 r = (struct node *) malloc (sizeof(struct node));
		 r ->d = num;
		 r->e=x;
		 r ->l = NULL;
		 temp ->l= r;
	}
}
void add(struct node *x,struct node *y)
{
	struct node *c;
	c=NULL;
	while(x!=NULL && y!=NULL)
	{
		if(x->e<y->e)
		{
			printf("\nCHECK\n");
			append(&c,y->d,y->e);
			y=y->l;
		}
		else if(x->e>y->e)
		{
			append(&c,x->d,x->e);
			x=x->l;
		}
		else
		{
			int s=y->d+x->d;
			append(&c,s,y->e);
			x=x->l;
			y=y->l;
		}
	}
	if(x!=NULL)
	while(x!=NULL)
	{
		append(&c,x->d,x->e);
		x=x->l;
    }
    if(y!=NULL)
    while(y!=NULL)
	{
		append(&c,y->d,y->e);
		y=y->l;
    }
	printf("\nRESULTANT POLYNOMIAL:\n");
	disp(c);
}

void disp(struct node *x)
{
	
	while(x!=NULL)
	{
		printf("%dX%d ",x ->d,x->e);
		x = x->l;
	}
}
