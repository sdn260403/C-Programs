#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
 };
 void append(struct node **,int);
 void addatbeg (struct node **, int);
 void display (struct node *);
 void search(struct node *,int);
 void count_nodes(struct node *);
 void sum_eveodd(struct node *);
 void insert(struct node *,int,int);
 void del(struct node**,int);
 void reverse(struct node**);
 
 int main()
 {
 	struct node *p;
 	p=NULL;
 	int ch,x;
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1:printf("Enter data : ");
 				   scanf("%d",&x);
 				   append(&p,x);
 				   break;
 			case 2:printf("Enter data : ");
 				   scanf("%d",&x);
 				   addatbeg(&p,x);
 				   break;
 			case 3:display(p);
 				   break;
		 }
	 }while(ch!=0);
 }
 void append (struct node **q, int num)
{
	struct node *temp, *r;
	if (*q == NULL) 			// if the list is empty, create first node
	{
		temp = (struct node *) malloc (sizeof(struct node));
		//temp = malloc(sizeof(struct node));
      //temp=new node;
		temp ->data = num;
		temp ->link = NULL;
		*q = temp;
	}

	else
	{
		temp = *q;
		/* go to last node */
		 while (temp ->link != NULL)
		 temp = temp ->link;

		 /* add node at the end */
		 r = (struct node *) malloc (sizeof(struct node));
       //r=new node;
		 r ->data = num;
		 r ->link = NULL;
		 temp ->link = r;
	}
}
void addatbeg (struct node **q, int num)
{
	struct node *temp;

	/* add new node */

	temp = (struct node *) malloc(sizeof (struct node));
 
	temp ->data=num;
	temp ->link = *q;
	*q = temp;

}
void display (struct node *q)
{
	printf ("\n");
	/* traverse the entire linkd list */
   if (q == NULL)
   {
   	printf("LinkedList is empty");
      return;
   }
	while (q != NULL)
	{
		printf ("%d ", q-> data);
		q = q ->link;
	}
}
void search(struct node *q,int key)
{
	struct node *temp;
	temp=q;
	while(temp!=NULL)
	{
		if(temp ->data == key)
		{
			printf("FOUND");
			return;
		}
		temp=temp->link;
	}
	printf("NOT FOUND");
}
void count_nodes(struct node *q)
{
	int c=0;
	while(q!=NULL)
	{
		c+=1;
		q=q->link;
	}
	printf("NUMBER OF NODES : %d",c);
}
void sum_of_eveodd(struct node *q)
{
	int e=0,o=0;
	while(q!=NULL)
	{
		if(q ->data%2==0)
		e+= q ->data;
		else 
		o+= q ->data;
		q=q ->link;
	}
	printf("EVEN : %d ODD : %d",e,o);
}
void insert(struct node *q,int num,int pos)
{
	int i;
	struct node *temp;
	for(i=1;i<pos;i++)
		q=q->link;
	temp=(struct node *)malloc(sizeof(struct node*));
	temp->link=q->link;
	q->link=temp;
	temp->data=num;
}
void del(struct node **q,int num)
{
	struct node *old,*temp;
	temp=*q;
	while(temp->data!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==*q)
				*q=temp->link;
			else
				old->link=temp->link;
			free(temp);
			return;
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
	}
	printf("\n ELEMENT %d NOT FOUND\n",num);
}
void reverse(struct node**q)
{
	struct node *prvNode,*nextNode,*currentNode;
	currentNode=*q;
	prvNode=NULL;
	while(currentNode!=NULL)
	{
		nextNode=prvNode;
		prvNode==currentNode;
		currentNode=currentNode->link;
		prvNode->link=nextNode;
	}
	*q=prvNode;
}










