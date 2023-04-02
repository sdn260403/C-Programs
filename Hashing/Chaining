#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node_1
{
	int d;
	struct node_1 *l;
}n1;
typedef struct node_2
{
	int d;
	struct node_1 *ll;
	struct node_2 *p;
	struct node_2 *n;
}n2;
 n2 *p;
 void display(int);
 void i_s(n1**,int,int);
 void i_d(int,int);
 
 int main()
 {
 	
 	p=NULL;
 	int ch,x,l,y;
 	printf("\nEnter 0 to exit\nEnter 1 to enter\nEnter 2 to display");
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:printf("Enter Number Length: ");
 				   scanf("%d",&l);
			 	   printf("Enter Number : ");
 				   scanf("%d",&x);
 				   i_d(x,l);
 				   break;
 			case 2:printf("Enter Digit : ");
 				   scanf("%d",&y);
 				   display(y);
 				   break;
		 }
	 }while(ch!=0);
}
void i_d(int x,int l)
{
	
	n2 *temp,*q,*old=NULL;
	q=p;
	
	temp=(n2*)malloc(sizeof(n2));
	temp->d=(int)(x/pow(10,l-1));
	temp->ll=NULL;
	
	if(p==NULL)
	{
		temp->p=NULL;
		temp->n=NULL;
		p=temp;
		q=temp;
	}
	else
	{
		while(q!=NULL && q->d < temp->d)
		{
			old=q;
			q=q->n;
		}
		if(q==NULL)
		{
			old->n=temp;
			temp->p=old;
			temp->n=NULL;
			q=temp;
		}
		else if(q->d < temp->d)
		{
			temp->n=q->n;
			q->n=temp;
			temp->p=q;
			q=temp;
		}
	}
	i_s(&q->ll,x,l);
}
void i_s(n1 **q,int x,int l)
{
	n1 *temp,*old,*y;
	y=*q;
	old=NULL;
	temp=(n1*)malloc(sizeof(n1));
	temp->d=x;
	
	if(*q==NULL)
	{
		temp->l=NULL;
		*q=temp;
		
	}
	else
	{
		while(y!=NULL && x>y->d)
		{
			old=y;
			y=y->l;
		}
		if(y==NULL)
		{
			old->l=temp;
			temp->l=NULL;
		}
		else if(y==*q)
		{
			*q=temp;
			temp->l=y;
		}
		else
		{
			old->l=temp;
			temp->l=y;
		}
	}
}
void display(int x)
{
	n2 *q=p;
	n1 *y;
	while(q!=NULL && q->d!=x )
	q=q->n;
	if(q==NULL)
	printf("NOT FOUND");
	else
	{
		y=q->ll;
		while(y!=NULL)
		{
			printf("%d ",y->d);
			y=y->l;
		}
	}

}

