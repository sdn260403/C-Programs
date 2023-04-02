#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define waiting 2
#define visited 3
struct adj_m
{
    int **a,n,*state;
};
struct queue
{
    int front,rear,n;
    int *a;
};

void insert(struct queue *x,int d)
{
	if(x->a[x->rear] ==x->n-1)
	{
		printf("ERROR");
        exit(0);
    }
	else
	{
        if(x->front==-1)
            x->front=0;
	    x->rear+=1;
	    x->a[x->rear]=d;
	}
}

int del(struct queue *x)
{
    int val;
	if(x->front==-1 || x->front>x->rear)
    {
		printf("ERROR");
        exit(0);
    }
	else
	{
        val=x->a[x->front];
        x->front+=1;
    }
	return val;
}

int isEmpty(struct queue *x)
{
    if(x->front==-1 || x->front>x->rear)
        return 1;
    else
        return 0;
} 

void display_graph(struct adj_m *x)
{
    int i,j;
    for(i=0;i<x->n;i++)
    {
        for(j=0;j<x->n;j++)
        {
            printf("%d ",x->a[i][j]);
        }
        printf("\n");
    }
}

void create_graph(struct adj_m *x)
{
   int i,e,o,d;
   printf("ENTER NUMBER OF EDGES :");
   scanf("%d",&e);
   for(i=1;i<=e;i++)
   {
       printf("Enter origin and destination of edge %d: \n",i);
       scanf("%d %d", &o,&d);

       if(o>=x->n || d>=x->n || o<0 || d<0)
       {
           printf("Invalid vertex\n");
           i--;
       }
       else 
            x->a[o][d]=1;
       
   }
}

void BFS(struct adj_m *x,int v)
{
    int i;
    struct queue y;
    y.front=-1;
    y.rear=-1;
    y.n=x->n;
    y.a=(int*)malloc(sizeof(int)*x->n);
    insert(&y,v);
    x->state[v]=waiting;
    while(!isEmpty(&y))
    {
        v=del(&y);
        printf("%d ",v);
        x->state[v]=visited;
        for(i=0;i<x->n;i++)
        {
            if(x->a[v][i]==1 && x->state[i]==initial)
            {
                insert(&y,i);
                x->state[i]=waiting;
            }
        }
    }
    printf("\n");
}

void Start(struct adj_m *x)
{
    int i,j,y;
    for(i=0;i<x->n;i++)
    {
        x->state[i]=initial;
    }
    printf("Enter Start Vertex for BFS: \n");
    scanf("%d", &y);
    BFS(x,y);
}



void main()
{
    int i,j;
    struct adj_m b;
    printf("Enter the number of vertices: \n");
    scanf("%d", &b.n);
    b.a=(int**)malloc(b.n*sizeof(int*));
    for(i=0;i<b.n;i++)
    {
        b.a[i]=(int*)malloc(b.n*sizeof(int));
    }
    b.state=(int*)malloc(b.n*sizeof(int));
    for(i=0;i<b.n;i++)
    {
        for(j=0;j<b.n;j++)
        {
            b.a[i][j]=0;
        }
    }
    create_graph(&b);
    printf("\nThe Graph is: \n");
    display_graph(&b);
    printf("\nThe BFS Traversal is: \n");
    Start(&b);
}
