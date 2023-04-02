#include <stdio.h>
#include <stdlib.h>
typedef struct graph
{
    int v,e;
    int **a;
}g;
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

void fill(int *x,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
}
void prim(g *s,int *ans)
{
    int i,j,x,y;
    while(s->e<=s->v-1)
    {
        int min=999999;
        x=0;
        y=0;
        for(i=0;i<s->v;i++)
        {
            if(ans[i])
            {
                for(j=0;j<s->v;j++)
                {
                    if(ans[j]==0 && s->a[i][j])
                    {
                        if(s->a[i][j]<min)
                        {
                            min=s->a[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d->%d : %d\n",x,y,min);
        s->e+=1;
        ans[y]=min;
    }
    
}

int main()
{
    int i,*ans;
    g s;
    printf("ENTER NUMBER OF VERTICES: ");
    scanf("%d",&s.v);
    s.a=(int**)malloc(sizeof(int*)*s.v);
    ans=(int*)malloc(sizeof(int)*s.v);
    fill(ans,s.v);
    for(i=0;i<s.v;i++)
        s.a[i]=(int*)malloc(sizeof(int)*s.v);
    adj_m(&s);

    printf("\nACCEPTED ADJACENCY MATRIX IS :\n");
    disp_m(&s);
    printf("\n");

    s.e=0;
    prim(&s,ans);
}
