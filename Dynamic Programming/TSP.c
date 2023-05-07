#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a>b)?b:a
//MEMOIZE WITH i,mask
//mask is an aternative for visited array
typedef struct req
{
        int **g,n;
        int v;
}r;
void read(r*);
void disp_graph(r);
int tsp(int,int,r);
void main()
{
        r s;
        read(&s);
        s.v=(1<<s.n)-1;
        
        printf("ACCEPTED GRAPH IS:\n");
        disp_graph(s);
        printf("Least Cost of Travelling is: %d\n",tsp(0,1,s));
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
int tsp(int i,int mask,r s)
{
        int ans=9999999,city;
        if(mask==s.v)
                return s.g[i][0];
        for(city=0;city<s.n;city++)
        {
                if((mask&(1<<city))==0)
                {
                        int res=s.g[i][city]+tsp(city,mask|(1<<city),s);
                        ans=min(ans,res);
                }
        }
        return ans;
}
                    
