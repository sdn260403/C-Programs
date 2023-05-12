#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};

void add(int,struct node **,struct node **);
void del(int,struct node **,struct node **);
void display (struct node **,struct node **);
int main()
 {
 	struct node *r=NULL,*f=NULL;
 	int ch,x;
 	printf("\n1 to insert\n2 to delete\n3 to display\n0 to exit");
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:printf("Enter data : ");
 				   scanf("%d",&x);
 				   add(x,&r,&f);
 				   break;
 			case 2:printf("Enter data to be deleted : ");
 				   scanf("%d",&x);
				   del(x,&r,&f);
 				   break;
 			case 3:display(&r,&f);
 				   break;
		 }
	 }while(ch!=0);
	 return 0;
 }
void add(int num,struct node **r,struct node **f)
{
	struct node *temp,*x;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->d=num;
	if(*f==NULL)
	{
	*f=temp;
	*r=temp;
	}
	else
	{
		x=*r;
		x->l= temp;
		x=x->l;
		temp->l=*f;
		*r=temp;
	}
}
void del(int a,struct node **r,struct node **f)
{
	if (*f == NULL)
    {
   		printf("LinkedList is empty");
      	return;
	}
		struct node *temp,*old,*x=*f,*y=*r;
		old=NULL;
		temp=*f;
		while(temp!=*r && temp->d !=a)
		{
			old=temp;
			temp=temp->l;
			
		}
		if(temp==*r && temp->d!=a)
			printf("ELEMENT NOT PRESENT\n");
		else
		{	if(temp->d==x->d && x!=y)
			{
				x=x->l;
				*f=x;
			}
			if(old!=NULL) 
		        	old->l=temp->l;
			if(temp->d==y->d && x!=y)
				*r=old;
		}
		if(*f==temp && *f==*r)
		{
			*f=NULL;
			*r=NULL;
		}
		
		free(temp);
}

void display (struct node **r,struct node **f)
{
	printf ("\n");
   if (*f == NULL)
   {
   	  printf("LinkedList is empty");
      return;
   }
    struct node *q=*f;
	while (q != *r)
	{
		printf ("%d ", q->d);
		q = q ->l;	
	}
	printf ("%d ", q->d );
}
