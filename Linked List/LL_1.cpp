#include <stdio.h>
#include <stdlib.h>
#define check(a,b) a<b
typedef struct node
{
	int d;
	struct node *l;
}n;
void append(n**,int);
void work(n**,int);
void disp(n*);
int main()
{
	int i,c1,c2,d;
	n *p;
	p=NULL;
	printf("Enter Number of nodes and sub list length: ");
	scanf("%d %d",&c1,&c2);
	if(check(c1,c2))
	{
		printf("WRONG INPUT");
		exit(0);
	}
	for(i=1;i<=c1;i++)
	{
		printf("ENTER DATA FOR NODE %d ",i);
		scanf("%d",&d);
		append(&p,d);
	}
	printf("ORIGINAL LIST : ");
	disp(p);
	work(&p,c2);
}
void append (n **q, int num)
{
	n *temp, *r;
	if (*q == NULL) 
	{
		temp = (n *) malloc (sizeof(n));
		temp->d= num;
		temp->l = NULL;
		*q = temp;
	}
	else
	{
		 temp = *q;
		 while (temp ->l != NULL)
		 temp = temp ->l;

		 r = (n*) malloc (sizeof(n));
       
		 r ->d = num;
		 r ->l = NULL;
		 temp ->l = r;
	}
}
void work(n **q, int y)
{
	n *temp,*z;
	temp=*q;
	for(int i=1;i<y-1;i++)
	{
		temp=temp->l;
	}
	z=temp->l;
	temp->l=NULL;
	printf("\nLIST 1 : ");
	disp(*q);
	printf("\nLIST 2 : ");
	disp(z);
}
void disp(struct node *x)
{
	while(x!=NULL)
	{
		printf("%d ",x ->d);
		x = x->l;
	}
}

