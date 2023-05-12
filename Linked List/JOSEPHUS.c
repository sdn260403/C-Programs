#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *l;
};

void add(int,struct node **,struct node **);
void josephus(int,struct node **,struct node **);
void display (struct node **,struct node **);
int count(struct node **,struct node **);

int main()
 {
 	struct node *r=NULL,*f=NULL;
 	int ch,x;
 	printf("\nENTER:\n1 to insert\n0 to finish entering\n");
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
		 }
	}while(ch!=0);
    printf("ACCEPTED ELEMENTS :-\n");
    display(&r,&f);
    printf("\nEnter length of circle : ");
 	scanf("%d",&x);
	josephus(x,&r,&f);
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

int count(struct node **r,struct node **f)
{
    int c=0;
    struct node *q;
    q=*f;
    while(q!=*r)
    {
        c+=1;
        q=q->l;
    }
    return c;
}


void josephus(int x,struct node **r,struct node **f)
{
    int i;
    struct node *q,*old,*temp;
    q=*f;
    old=NULL;
    if(count(r,f)==0)
        printf("LINKED LIST IS EMPTY \n");
    else
    {
        while(count(r,f)!=0)
        {
            for(i=1;i<x;i++)
                {
                    old=q;
                    q=q->l;
                }
            if(q==*r)
                *r=old;
            if(q==*f)
                *f=q->l;
            
            old->l=q->l;
            temp=q;
            q=q->l;
            free(temp);   
        }
    }
    
    printf("THE REMAINING ELEMENT IS : %d",q->d);
}
