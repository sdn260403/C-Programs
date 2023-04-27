#include<stdio.h>
#include<stdlib.h>
struct graph
{
        int **g,n,*col,c;
};
void disp(struct graph);
void disp_graph(struct graph);
void read(struct graph*);
int work(struct graph*,int);
int isPresent(struct graph*,int,int);
void main()
{
        struct graph s;
        read(&s);
        s.col=(int*)calloc(s.n,sizeof(int));
        printf("ACCEPTED GRAPH IS:\n");
        disp_graph(s);
        if(work(&s,0))
        {
                printf("SOLUTION:\n");
                disp(s);
        }
        else
                printf("NO SUCCESSFUL SOLUTION EXISTS");
        
}
void read(struct graph *x)
{
        int i,j;
        FILE *f;
        f=fopen("input.txt","r");
        fscanf(f,"%d",&x->n);
        fscanf(f,"%d",&x->c);
        x->g=(int**)malloc(x->n*sizeof(int*));
        for(i=0;i<x->n;i++)
        {
                x->g[i]=(int*)malloc(x->n*sizeof(int));
                for(j=0;j<x->n;j++)
                        fscanf(f,"%d",&x->g[i][j]);
        }
}
void disp_graph(struct graph x)
{
        int i,j;
        for(i=0;i<x.n;i++)
        {
                for(j=0;j<x.n;j++)
                        printf("%d ",x.g[i][j]);
                printf("\n");
        }
}
void disp(struct graph x)
{
        int i;
        for(i=0;i<x.n;i++)
                printf("%d ",x.col[i]);
        printf("\n");
}
int isPresent(struct graph *x,int v,int c)
{
        int i;
        for(i=0;i<x->n;i++)
                if(x->g[v][i] && c==x->col[i])
                        return 1;
        return 0;
}
int work(struct graph *x,int v)
{
        int i;
        if(v==x->n)
                return 1;
        for(i=1;i<=x->c;i++)
        {
                if(!isPresent(x,v,i))
                {
                        x->col[v]=i;
                        if(work(x,v+1))
                                return 1;
                        x->col[v]=0;
                }

        }
        return 0;
}
