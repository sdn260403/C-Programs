#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
}*p;
void accept(int);
void append (struct node**, int);
void sort(int);
void disp(struct node*);
int main()
{
	p=NULL;
	int n;
	printf("ENTER NUMBER OF ELEMENTS : ");
	scanf("%d",&n);
	accept(n);
	printf("OLD LIST :\n");
	disp(p);
	printf("\nSORTED LIST :\n");
	sort(n);
	disp(p);
}
void accept(int n)
{
	int i,num;
	for(i=0;i<n;i++)
	{
		printf("ENTER VALUE : ");
		scanf("%d",&num);
		append(&p,num);
	}
}

void append (struct node **q, int num)
{
	struct node *temp, *r;
	if (*q == NULL) 		
	{
		temp = (struct node *) malloc (sizeof(struct node));
		temp ->d = num;
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
		 r ->l = NULL;
		 temp ->l = r;
	}
}
void sort(int n)
{
	int x=0;
	struct node *temp,*s,*l;
	l=NULL;
	do
	{
		s=p;
		x=0;
		while(s->l!=l)
		{
			if(s->d>s->l->d)
			{
				temp->d=s->d;
				s->d=s->l->d;
				s->l->d=temp->d;
				x=1;
			}
		s=s->l;
		}
		l=s;
	}while(x);
}
void disp(struct node *x)
{
	while(x!=NULL)
	{
		printf("%d ",x->d);
		x=x->l;
	}
}
