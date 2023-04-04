#include<stdio.h>
#include<stdlib.h>
struct adj_m
{
    int **a,n,e,*parent,*rank;
};
void display_graph(struct adj_m *x)
{
    int i;
    for(i=0;i<x->e;i++)
    {
        printf("%d %d : %d",x->a[i][0],x->a[i][1],x->a[i][2]);
        printf("\n");
    }
}
int findPar(struct adj_m *s,int v)
{
    if(s->parent[v]==v)
        return v;
    return s->parent[v]=findPar(s,s->parent[v]);
}
void unionS(struct adj_m *s,int u,int v)
{
    int par_u=s->parent[u],par_v=s->parent[v];
    if(par_u==par_v)
        return;
    if(s->rank[par_u]<s->rank[par_v])
        s->parent[par_u]=par_v;
    else if(s->rank[par_u]>s->rank[par_v])
        s->parent[par_v]=par_u;
    else
    {
        s->parent[par_v]=par_u;
        s->rank[par_u]+=1;
    }
}
void b_sort(struct adj_m *s)
{
	int i,j,*t;
	for(i=0;i<s->e;i++)
	{
		for(j=0;j<s->e-i-1;j++)
		{
			if(s->a[j][2]>s->a[j+1][2])
			{
				t=s->a[j];
				s->a[j]=s->a[j+1];
				s->a[j+1]=t;
			}
		}
	}
}
void create_graph(struct adj_m *x)
{
   int i,o,d,val;
   printf("ENTER NUMBER OF EDGES :");
   scanf("%d",&x->e);
   x->a=(int**)malloc(x->e*sizeof(int*));
   for(i=1;i<=x->e;i++)
   {
       printf("Enter origin, destination and value of edge %d: \n",i);
       scanf("%d %d %d", &o,&d,&val);

       if(o>=x->n || d>=x->n || o<0 || d<0)
       {
           printf("Invalid vertex\n");
           i--;
       }
       else 
        {
            x->a[i-1]=(int*)malloc(3*sizeof(int));
            x->a[i-1][0]=o;
            x->a[i-1][1]=d;
            x->a[i-1][2]=val;
        }   
   }
}
void krusA(struct adj_m *x)
{
    b_sort(x);
    int minc=0,i;
    for(i=0;i<x->e;i++)
    {
        int u,v;
        u=findPar(x,x->a[i][0]);
        v=findPar(x,x->a[i][1]);
        if(u!=v)
        {
            unionS(x,u,v);
            printf("%d   %d : %d\n",x->a[i][0],x->a[i][1],x->a[i][2]);
            minc+=x->a[i][2];
        }
    }
    printf("\nMINIMUM COST: %d",minc);
}
void Start(struct adj_m *x)
{
    int i,j,y;
    for(i=0;i<x->n;i++)
    {
        x->parent[i]=i;
        x->rank[i]=0;
    }
    
    krusA(x);
}

void main()
{
    int i,j;
    struct adj_m b;
    printf("Enter the number of vertices: \n");
    scanf("%d", &b.n);
    
    b.parent=(int*)malloc(b.n*sizeof(int));
    b.rank=(int*)malloc(b.n*sizeof(int));
    
    create_graph(&b);
    printf("\nThe Graph is: \n");
    display_graph(&b);
    printf("\nThe Kruskal Traversal is: \n");
    Start(&b);
}
/*TO READ FROM A FILE
void read_from_file(struct adj_m *b)
{
	FILE *fp;
	int i,j,n;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&b->n);
	char read[b->n*2];
	
	b->graph=(int**)malloc(b->n*sizeof(int*));
	for(i=0;i<b->n;i++)
	{
		b->graph[i]=(int*)malloc(b->n*sizeof(int));
		for(j=0;j<b->n;j++)
			fscanf(fp,"%d",&b->graph[i][j]);
	}
	fclose(fp);
}
*/
