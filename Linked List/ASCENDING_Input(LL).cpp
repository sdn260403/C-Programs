#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};
void add(struct node**,int);
void addatbeg(struct node**,int);
void append(struct node**,int);
void insert(struct node**,struct node*,int);
void disp(struct node*);
int main()
{
	struct node *p;
	p=NULL;
	int c,z;
	printf("\nEnter 0 to exit \nEnter 1 to accept\nEnter 2 to display ");
	do
	{
		printf("\nEnter Choice ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("ENTER DATA ");
				   scanf("%d",&z);
				   add(&p,z);
				   break;
			case 2:disp(p);
				   break;
		}
	}while(c!=0);
	return 0;
}
void add(struct node **q,int n)
{
	struct node *temp,*r,*s;
	if(*q==NULL)
	{
		temp=(struct  node * )malloc(sizeof(struct node* ));
		temp->d=n;
		temp->l=NULL;
		*q=temp;
	}
	else
	{
		s=*q;
		r=*q;
		while(r->d<n||r->l!=NULL)
			r=r->l;
		if(r->l==NULL)
		append(q,n);
		else if(n<r->d && r==*q)
		addatbeg(q,n);
		else
		{
			while(s->l!=r)
			s=s->l;
			insert(&r,s,n);
		}
	}
}
void append(struct node **q,int n)
{
	printf("CHECK");
	struct node *temp,*r;
	r=*q;
	while (r->l!= NULL)
	r=r->l;
	temp=(struct node *)malloc(sizeof(struct node* ));
	temp->l=NULL;
	temp->d=n;
	r->l=temp;
}
void addatbeg(struct node **q,int n)
{
	struct node *temp;
	temp=(struct node * )malloc(sizeof(struct node* ));
	temp->d=n;
	temp->l=*q;
	*q=temp;
	
}

void insert(struct node **q,struct node *s,int n)
{
	struct node *temp;
	temp=(struct node * )malloc(sizeof(struct node* ));
	temp->d=n;
	temp->l=*q;
	s->l=temp;
}

void disp(struct node *q)
{
	printf ("\n");
   if (q == NULL)
   {
   	printf("LinkedList is empty");
      return;
   }
	while (q != NULL)
	{
		printf ("%d ", q-> d);
		q = q ->l;
	}
}
