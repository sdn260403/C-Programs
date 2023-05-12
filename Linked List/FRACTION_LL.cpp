#include<stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b)?a:b
struct node
{
	int w;
	int d;
	int n;
	struct node *l;
};
int lcm(int x,int y)
{
	int l=MAX(x,y);
	while(true)
	{
		if(l%x==0 && l%y==0)
		return l;
		l+=1;
	}
}

int hcf(int x,int y)
{
	int i;
	for(i=MAX(x,y);i>=1;i--)
	{
		if(x%i==0 && y%i==0)
		return i;
	}
}

struct node* improper(struct node* x)
{
x->n=x->w*x->d+x->n;
x->w=0;
return x;
}
struct node* reduce(struct node*);
void add(struct node *,struct node *);
struct node * accept();
void disp(struct node*);
int main()
{
	struct node *F1,*F2;
	F1=NULL;
	F2=NULL;
	F1=accept();
	F1=reduce(F1);
	printf("\nFRACTION 1 :- ");
	disp(F1);
	F1=improper(F1);
	printf("\nIMPROPER FRACTION 1 :- ");
	disp(F1);

	F2=accept();
	F2=reduce(F2);
	printf("\nFRACTION 2 :- ");
	disp(F2);
	F2=improper(F2);
	printf("\nIMPROPER FRACTION 2 :- ");
	disp(F2);

	add(F1,F2);
}

struct node * accept()
{
	struct node *temp;
	temp = (struct node *) malloc (sizeof(struct node));
	
	printf("\nENTER WHOLE NUMBER :- ");
	scanf("%d",&temp->w);

	printf("\nENTER NUMERATOR :- ");
	scanf("%d",&temp->n);

	printf("\nENTER DENOMINATOR :- ");
	scanf("%d",&temp->d);
	
	temp->l=NULL;
	return temp;
}

struct node* reduce(struct node *x)
{
	int z=hcf(x->n,x->d);
	x->d/=z;
	x->n/=z;
	return x;
}

void add(struct node *x,struct node *y)
{
	struct node *z;
	z = (struct node *) malloc (sizeof(struct node));
	int a=lcm(x->d,y->d);
	z->n=(a/x->d*x->n)+(a/y->d*y->n);
	z->d=a;
	if(z->n>z->d)
	{
		z->w=z->n / z->d;
		z->n=z->n % z->d;
	}
	else
		z->w=0;
	printf("\nRESULTANT FRACTION :- ");
	disp(z);
}

void disp(struct node *x)
{
	printf("%d %d/%d",x->w,x->n,x->d);
}
