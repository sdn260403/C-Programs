#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
    int v,start;
    int **a,*ans;
}g;
void fill(int *x,int n)
{
    int i;
    for(i=0;i<n;i++)
        x[i]=-1;
}

void disp(int dist[],int V)
{
    int i;
    printf("Vertex -> Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d ------> %d\n", i+1, dist[i]);
}

int minDist(g *s,int *y)
{
    int idx,i,m=99999999;
    for(i=0;i<s->v;i++)
    {
        if(y[i]!=1 && s->ans[i]!=-1 && s->ans[i]<m)
        {
            idx=i;
            m=s->ans[i];
        }
    }
    return idx;
}
/*
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
*/
void dijkstras(g s)
{
    int i,j,temp,*check;
    check=(int*)malloc(sizeof(int)*s.v);
    fill(check,s.v);
    s.ans[s.start]=0;
    for(i=1;i<s.v;i++)
    {
        temp=minDist(&s,check);
        check[temp]=1;
        for(j=0;j<s.v;j++)
        {
            if(check[j]!=1  && s.a[temp][j] && s.ans[j]==-1)
                s.ans[j]=s.ans[temp]+s.a[temp][j];
            else if( check[j]!=1  && s.a[temp][j] && s.ans[temp]+s.a[temp][j]<s.ans[j])
                s.ans[j]=s.ans[temp]+s.a[temp][j];
        }
    }
    disp(s.ans,s.v);
}


void adj_m(g *s)
{
    int i,j;
    for(i=0;i<s->v;i++)
    {
        for(j=0; j<s->v;j++)
        {
            
            printf("ENTER WEIGHT OF %d WITH RESPECT TO %d: ",(j+1),(i+1));
            scanf("%d",&s->a[i][j]);
            
        }
    }
}
void disp_m(g *s)
{
    int i,j;
    for(i=0;i<s->v;i++)
    {
        for(j=0;j<s->v;j++)
            printf("%d ",s->a[i][j]);
        printf("\n");
    }
}
int main()
{
    int i;
    g S;
    printf("ENTER NUMBER OF VERTICES: ");
    scanf("%d",&S.v);
    S.a=(int**)malloc(sizeof(int*)*S.v);
    S.ans=(int*)malloc(sizeof(int)*S.v);
    fill(S.ans,S.v);

   for(i=0;i<S.v;i++)
        S.a[i]=(int*)malloc(sizeof(int)*S.v);
    adj_m(&S);

    printf("\nACCEPTED ADJACENCY MATRIX IS :\n");
    disp_m(&S);
    printf("\n");

    printf("ENTER STARTING VERTEX: ");
    scanf("%d",&S.start);
    dijkstras(S);
    
}
