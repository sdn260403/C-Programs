#include<stdio.h>
#include<stdlib.h>
#define initial 1
#define visited 2
#define min(a,b) (a>b)?b:a
struct adj_m
{
    int **a,n,*state,*parent,**r_g;
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
   int i,e,o,d,val;
   printf("ENTER NUMBER OF EDGES :");
   scanf("%d",&e);
   for(i=1;i<=e;i++)
    {
       printf("Enter origin,destination and value of edge %d: \n",i);
       scanf("%d %d %d", &o,&d,&val);

       if(o>=x->n || d>=x->n || o<0 || d<0)
       {
           printf("Invalid vertex\n");
           i--;
       }
       else 
            x->a[o][d]=val;
    }
}
void initialize(struct adj_m *x)
{
    int i,j,y;
    for(i=0;i<x->n;i++)
        x->state[i]=initial;
    
}
int BFS(struct adj_m *x,int s,int t)
{
    int i;
    struct queue y;
    y.front=-1;
    y.rear=-1;
    y.n=x->n;
    y.a=(int*)malloc(sizeof(int)*x->n);
    initialize(x);
    insert(&y,s);
    x->state[s]=visited;
    while(!isEmpty(&y))
    {
        int u=del(&y);
        
        for(i=0;i<x->n;i++)
        {
            if(x->r_g[u][i]>0 && x->state[i]==initial)
            {
                if(i==t)
                {
                    x->parent[i]=u;
                    return 1;
                }
                insert(&y,i);
                x->parent[i]=u;
                x->state[i]=visited;
            }
        }
    }
    return 0;
}
void ford_fulkerson(struct adj_m *x,int s,int t)
{
    int u,v,max_flow=0;
    for(u=0;u<x->n;u++)
        for(v=0;v<x->n;v++)
            x->r_g[u][v]=x->a[u][v];
    while(BFS(x,0,x->n-1))
    {
        int path_flow=1e9;
        for(v=t;v!=s;v=x->parent[v])
        {
            u=x->parent[v];
            path_flow=min(path_flow,x->r_g[u][v]);
        }
        for(v=t;v!=s;v=x->parent[v])
        {
            u=x->parent[v];
            x->r_g[u][v]-=path_flow;
            x->r_g[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    printf("\nMAXIMUM FLOW OF THE GRAPH IS : %d",max_flow);
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
        b.r_g[i]=(int*)malloc(b.n*sizeof(int));
    }
    b.state=(int*)malloc(b.n*sizeof(int));
    b.parent=(int*)malloc(b.n*sizeof(int));

    for(i=0;i<b.n;i++)
        for(j=0;j<b.n;j++)
        {
            b.a[i][j]=0;
            b.r_g[i][j]=0;
        }

    create_graph(&b);
    printf("\nThe Graph is: \n");
    display_graph(&b);
    
    ford_fulkerson(&b,0,b.n-1);
}
