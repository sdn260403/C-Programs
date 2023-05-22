#include<stdio.h>
#include<stdlib.h>
#define INF 99999999
#define mini(a,b) (a>b)?b:a
struct graph
{
        int **a,n,*dist,*vis;
};
void disp_graph(struct graph g)
{
        int u,v;
        for(u=0;u<g.n;u++)
        {
                for(v=0;v<g.n;v++)
                        printf("%d ",g.a[u][v]);
                printf("\n");
        }
        printf("%d",g.n);
}
void disp_ans(struct graph g)
{
        int u;
        printf("Vertex-->Distance from Source\n");
        for(u=0;u<g.n;u++)
                printf("%d------------->%d\n",u+1,g.dist[u]);
        
}
void fill(int *a,int n)
{
        int i;
        for(i=0;i<n;i++)
                a[i]=INF;
}
int min_dist(struct graph *g)
{
        int i,idx,min=INF;
        for(i=0;i<g->n;i++)
        {
                if(g->vis[i]==INF && g->dist[i]<min)
                {
                        idx=i;
                        min=g->dist[i];
                }
        }
        return idx;
}
void dijkstra(struct graph g,int src)
{
        int i,j,temp;
        g.dist[src]=0;
        printf("%d",g.n);
        for(i=1;i<g.n;i++)
        {
                temp=min_dist(&g);
                g.vis[temp]=0;
                for(j=0;j<g.n;j++)
                        if(g.vis[j] && g.a[temp][j])
                                g.dist[j]=mini(g.dist[j],g.dist[temp]+g.a[temp][j]);

        }
        disp_ans(g);
}
void read_from_file(struct graph *g)
{
        int i,j;
        FILE *f;
        f=fopen("input.txt","r");
        fscanf(f,"%d",&g->n);
        g->a=(int**)malloc(g->n*sizeof(int*));
        for(i=0;i<g->n;i++)
        {
                g->a[i]=(int*)malloc(g->n*sizeof(int));
                for(j=0;j<g->n;j++)
                        fscanf(f,"%d",&g->a[i][j]);
        }
}
void main()
{
        struct graph g;
        read_from_file(&g);
        g.dist=(int*)calloc(g.n,sizeof(int));
        g.vis=(int*)calloc(g.n,sizeof(int));
        fill(g.dist,g.n);
        fill(g.vis,g.n);
        printf("ACCEPTED GRAPH ::-\n");
        disp_graph(g);
        dijkstra(g,0);
}
