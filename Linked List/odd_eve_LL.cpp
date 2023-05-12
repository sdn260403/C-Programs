#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int d;
	struct node *l;
}n;
void append(n**,int);
void work(n**);
void disp(n*);
int main()
{
	int i,c1,d;
	n *p;
	p=NULL;
	printf("Enter Number of nodes ");
	scanf("%d",&c1);
	for(i=1;i<=c1;i++)
	{
		printf("ENTER DATA FOR NODE %d ",i);
		scanf("%d",&d);
		append(&p,d);
	}
	printf("ORIGINAL LIST : ");
	disp(p);
	work(&p);
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
void work(n **q)
{
	n *temp,*z,*old,*r;
	z=NULL;
	temp=*q;
	old=NULL;
	while(temp!=NULL)
	{
		if(temp->d%2==0)
		{
			if(z==NULL)
			{
				z=temp;
				if(old!=NULL)
				old->l=z->l;
				r=z;
			}
			else
			{
				if(z->l->d%2==0)
				{
					z=z->l;
					if(old!=NULL)
					old->l=z->l;
				}
				else
				{
				z->l=temp;
				old->l=temp->l;
				z=z->l;
				}
			}
		}
		else
		if(old==NULL)
		{
			old=temp;
			*q=old;
		}
		else
		old=temp;
		temp=temp->l;	
	}
	printf("\nEVEN LIST : ");
	if(z==NULL)
	printf("EMPTY");
	else
	{
		z->l=NULL;
		disp(r);
	}
		
	printf("\nODD LIST : ");
	if(old==NULL)
	printf("EMPTY");
	else
	{
		old->l=NULL;
		disp(*q);
	}

}
void disp(struct node *x)
{
	
	while(x!=NULL)
	{
		printf("%d ",x ->d);
		x = x->l;
	}
}

