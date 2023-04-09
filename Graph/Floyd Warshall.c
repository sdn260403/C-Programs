#include<stdio.h>
#include<stdlib.h>
#define INF 999999
#define min(a,b) (a>b)?b:a
struct graph
{
        int **g;
        int n;
};
void input(struct graph *s)
{
        int i,j;
        for(i=0;i<s->n;i++)
        {
                for(j=0;j<s->n;j++)
                {
                        printf("ENTER EDGE WEIGHT FOR EDGE (%d %d): ",(i+1),(j+1));
                        scanf("%d",&s->g[i][j]);
                        if(s->g[i][j]==-1)
                                s->g[i][j]=INF;
                }
        }
}
void fw(struct graph *s)
{
        int i,j,k;
        for(k=0;k<s->n;k++)
                for(i=0;i<s->n;i++)
                        for(j=0;j<s->n;j++)
                                s->g[i][j]=min(s->g[i][j],s->g[i][k]+s->g[k][j]);
}
void disp(struct graph *s)
{
        int i,j;
        for(i=0;i<s->n;i++)
        {
                for(j=0;j<s->n;j++)
                        if (s->g[i][j] == INF)
                                printf("%7s", "INF");
                        else
                                printf("%7d", s->g[i][j]);
                printf("\n");
        }
}
void main()
{
        int x;
        struct graph s;
        printf("ENTER NUMBER OF VERTICES : ");
        scanf("%d",&s.n);
        s.g=(int**)calloc(s.n,sizeof(int*));
        for(x=0;x<s.n;x++)
                s.g[x]=(int*)calloc(s.n,sizeof(int));
        printf("ENTER GRAPH:\n");
        input(&s);
        printf("ACCEPTED GRAPH IS:\n");
        disp(&s);
        fw(&s);
        printf("RESULT GRAPH :\n");
        disp(&s);
}
