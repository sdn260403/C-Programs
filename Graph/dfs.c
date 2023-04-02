#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
typedef struct node_1
{
	int d;
	struct node_1 *l;
}n1;
typedef struct node_2
{
	int d;
	struct node_1 *ll;
	struct node_2 *n;
}n2;


void display(n2 *p)
{
	n2 *q=p;
	n1 *y;
	while(q!=NULL )
	{
        printf("%d : ",q->d);
		y=q->ll;
		while(y!=NULL)
		{
			printf("%d ",y->d);
			y=y->l;
		}
        q=q->n;
        printf("\n");
	}

}

void create_graph(n2 *x,int num)
{
   int i,j,e,d;
   n1 *t,*old;
   old=NULL;
   for(i=1;i<=num;i++)
   {
        printf("Enter number destination edges of %d: ",x->d);
        scanf("%d",&d);
        fflush(stdin);
        old=NULL;
        for(j=0;j<d;j++)
        {
            printf("Enter destination edge %d :",j+1);
            scanf("%d",&e);
            if( e >= num || e<0 || e==x->d)
            {
                printf("Invalid vertex\n");
                j-=1;
            }
            else
            {
                t=(n1*)malloc(sizeof(n1));
	            t->d=e;
                t->l=NULL;
                if(old==NULL)
                {
                    x->ll=t;
                    old=t;
                }
                else
                {
                    old->l=t;
                    old=old->l;
                }
            }
        }
        x=x->n;  
   }
}

void DFS(n2 *x,int v,int *s)
{
    n1 *temp=x->ll;
    s[v]=visited;
    printf("%d ",v);
    while (temp != NULL) 
    {
        int cv = temp->d;
        if (s[cv] == initial) 
            DFS(x->n,cv,s);
        temp = temp->l;
    }
}

void Start(n2 *x,int num,int *s)
{
    int i,j,y;
    for(i=0;i<num;i++)
    {
        s[i]=initial;
    }
    printf("Enter Start Vertex for DFS: ");
    scanf("%d", &y);
    DFS(x,y,s);
}

void main()
{
    int i,j,num,*s;
    n2 *b,*x,*temp;
    x=NULL;
    printf("Enter the number of vertices: ");
    scanf("%d", &num);
    s=(int*)malloc(sizeof(int)*num);
    for(i=0;i<num;i++)
    {
	    temp=(n2*)malloc(sizeof(n2));
	    temp->d=i;
	    temp->ll=NULL;
        temp->n=NULL;
	    if(x==NULL)
        {
		    x=temp;
            b=temp;
        }
        else
        {
            x->n=temp;
            x=x->n;
        }  
    }
    create_graph(b,num);
    printf("\nAdjacency List: \n");
    display(b);
    printf("\nThe DFS Traversal is: \n");
    Start(b,num,s);
}
