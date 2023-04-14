#include<stdio.h>
#include<stdlib.h>
#define INF 999999
#define min(a,b) (a>b)?b:a
struct edge 
{
    int src,dest,weight;
};
typedef struct graph
{
    int v,e,start;
    int *ans;
    struct edge *ed;
}g;

void create_graph(struct graph *x)
{
   int i;
   for(i=1;i<=x->e;i++)
   {
       printf("Enter origin,destination and weightage of edge %d: \n",i);
       scanf("%d %d %d", &x->ed[i-1].src,&x->ed[i-1].dest,&x->ed[i-1].weight);

       if(x->ed[i-1].src>=x->v || x->ed[i-1].dest>=x->v || x->ed[i-1].src<0 || x->ed[i-1].dest<0)
        {
           printf("Invalid vertex\n");
           i--;
        }
   }
}

void fill(int *x,int n)
{
    int i;
    for(i=0;i<n;i++)
        x[i]=INF;
}

void disp(int dist[],int V)
{
    int i;
    printf("Vertex -> Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d ------> %d\n", i+1, dist[i]);
}

void bellmanford(g s)
{
    int i,j;
    s.ans[s.start]=0;
    for(i=1;i<s.v;i++)
    {
        for ( j = 0; j < s.e; j++) {
            int u = s.ed[j].src;
            int v = s.ed[j].dest;
            if (s.ans[u] != INF)
                s.ans[v] = min( s.ans[u] + s.ed[j].weight , s.ans[v]);
        }
    }
    for ( j = 0; j < s.e; j++)
    {
        int u = s.ed[j].src;
        int v = s.ed[j].dest;
        if (s.ans[u] != INF &&  s.ans[u] + s.ed[j].weight <s.ans[v])
        {
            printf("NEGATIVE CYCLE PRESENT");
            return;
        }
    }
    disp(s.ans,s.v);
}

int main()
{
    int i;
    g S;
    printf("ENTER NUMBER OF VERTICES: ");
    scanf("%d",&S.v);
    printf("ENTER NUMBER OF EDGES: ");
    scanf("%d",&S.e);
    S.ed=(struct edge *)malloc(sizeof(struct edge)*S.e);
    S.ans=(int*)malloc(sizeof(int)*S.v);
    fill(S.ans,S.v);
    create_graph(&S);

    printf("ENTER STARTING VERTEX: ");
    scanf("%d",&S.start);
    bellmanford(S);
    
}
