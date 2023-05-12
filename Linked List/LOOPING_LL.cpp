#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};
struct node *p,*f,*s,*y;
int a[100],n;
int looping(struct node*);
void ab (struct node **, int);
void disp();
int find();
int main()
{
	
	p=NULL;
	ab(&p,10);
	ab(&p,15);
	ab(&p,20);
	ab(&p,25);
	ab(&p,30);
	
	p->l->l->l->l->l=p->l->l;
	if(looping(p)==1)
	{
		printf("LOOPING PRESENT AT %d DATA",find());
		s->l=NULL;
		printf("\nMODIFIED LIST\n");
		disp();
	}
	else
		printf("NO LOOPING PRESENT");
}

void ab (struct node **q, int num)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof (struct node));
	temp ->d=num;
	temp ->l = *q;
	*q = temp;
}

int looping(struct node *x)
{
	f=x;
	s=x;
	n=1;
	a[0]=p->d;
	while(s && f && f->l)
	{
		f=f->l->l;
		s=s->l;
		a[n]=s->d;
		if(f==s)
		return 1;
		n+=1;
	}
	return 0;
}
int find()
{
	y=NULL;
	int i;
	while(true)
	{
		y=s->l;
		for(i=0;i<=n;i++)
		if(a[i]==y->d)
		return y->d;
		s=s->l;
	}
}
void disp()
{
	while(p!=NULL)
	{
	printf("%d  ",p->d);
	p=p->l;
	}
}
