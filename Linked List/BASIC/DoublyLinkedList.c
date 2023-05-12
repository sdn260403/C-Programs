#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *nxt;
	struct node *prv;
 };
 
 void display (struct node *);
 void insert(struct node **,int);
 void del(struct node**,int);
 void reverse(struct node *);
 
 int main()
 {
 	struct node *p;
 	p=NULL;
 	int ch,x;
 	printf("ENTER:\n1 to insert\n2 to delete\n3 to display reverse\n4 to display\n0 to exit");
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:printf("Enter data : ");
 				   scanf("%d",&x);
 				   insert(&p,x);
 				   break;
 			case 2:printf("Enter data : ");
 				   scanf("%d",&x);
 				   del(&p,x);
 				   break;
 			case 3:reverse(p);
 				  break;
 			case 4:display(p);
 				   break;
		}
	}while(ch!=0);
 }


void display (struct node *q)
{
	printf ("\n");
    if (q == NULL)
    {
   		printf("LinkedList is empty");
        return;
    }
	while (q != NULL)
	{
		printf ("%d ", q-> data);
		q=q->nxt;
	}
}

void insert(struct node **q,int num)
{
	struct node *temp,*r,*old=NULL;
	r=*q;
	temp=(struct node * )malloc(sizeof(struct node* ));
	if(*q == NULL)
	{
		temp->nxt=NULL;
		temp->prv=NULL;
		temp->data=num;
		*q=temp;
	}
	else
	{
		while(r!= NULL && r->data<num)
		{
			old=r;
			r=r->nxt;
		}
		temp->nxt=r;
		temp->prv=old;
		temp->data=num;
		if(old!=NULL)
		{
			old->nxt=temp;
			if(r!=NULL)
				r->prv=temp;
		}
		else
		{
			*q=temp;
			r->prv=*q;
		}
	}
	
}
void del(struct node **q,int num)
{
	struct node *temp;
	temp=*q;
	if(*q==NULL)
	{
		printf("LinkedList is Empty\n");
		return;
	}
	while(temp->data<=num)
	{
		if(temp->data==num)
		{
			if(temp == *q)
			{
				*q=temp->nxt;
				if(temp->nxt!=NULL)
					temp->nxt->prv=NULL;
			}
			else
			{
				temp->prv->nxt=temp->nxt;
				if(temp->nxt!=NULL)
					temp->nxt->prv=temp->prv;
			}
			
			printf("DATA DELETED : %d",temp->data);
			free(temp);
			return;
		}
		else
			temp=temp->nxt;
	}
	printf("\nELEMENT %d NOT FOUND\n",num);
}

void reverse(struct node *q)
{
	if(q==NULL)
	{
		printf("LinkedList is Empty\n");
		return;
	}
	while(q->nxt != NULL)
		q=q->nxt;
	printf("THE REVERSE OF THE DLL IS: \n\n");
	while(q!=NULL)
	{
		printf(" %d ",q->data);
		q=q->prv;
	}
}

