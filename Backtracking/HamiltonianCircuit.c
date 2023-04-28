#include<stdio.h>
#include<stdlib.h>
typedef struct req
{
        int **g,*vis,*ans,n;
}r;
void read(r*);
int isVal(int,int,r);
int cyclecheck(r*,int);
void disp_sol(r);
void disp_graph(r);
void main()
{
        r s;
        read(&s);
        s.ans=(int*)calloc(s.n,sizeof(int));
        s.vis=(int*)calloc(s.n,sizeof(int));
        printf("ACCEPTED GRAPH IS:\n");
        disp_graph(s);
        s.vis[0]=1;
        if(cyclecheck(&s,1))
        {
                printf("SOLUTION:\n");
                disp_sol(s);
        }
        else
                printf("NO SUCCESSFUL SOLUTION EXISTS\n");  
}
void read(r *x)
{
        int i,j;
        FILE *f;
        f=fopen("input.txt","r");
        fscanf(f,"%d",&x->n);
        x->g=(int**)malloc(x->n*sizeof(int*));
        for(i=0;i<x->n;i++)
        {
                x->g[i]=(int*)malloc(x->n*sizeof(int));
                for(j=0;j<x->n;j++)
                        fscanf(f,"%d",&x->g[i][j]);
        }
}
void disp_graph(r x)
{
        int i,j;
        for(i=0;i<x.n;i++)
        {
                for(j=0;j<x.n;j++)
                        printf("%d ",x.g[i][j]);
                printf("\n");
        }
}
void disp_sol(r x)
{
        int i;
        for(i=0;i<x.n;i++)
                printf("%d ",x.ans[i]);
        printf("\n");
}
int isVal(int v,int pos,r x)
{
       int i;
       if(!x.g[x.ans[pos-1]][v]) 
                return 0;
       for(i=0;i<pos;i++)
                if(x.ans[i]==v)
                        return 0;
       return 1;
}
int cyclecheck(r *x,int i)
{
        int v;
        if(i==x->n)
                return (x->g[x->ans[i-1]][x->ans[0]]==1);
        for(v=1;v<x->n;v++)
        {
                if(isVal(v,i,*x))
                {
                        x->ans[i]=v;
                        if(cyclecheck(x,i+1))
                                return 1;
                        x->ans[i]=0;
                }
        }
        return 0;
}
