#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a>b)?b:a
struct sf
{
    int p;
    int d;
    char ch;
};
void sort(struct sf **x,int n)
{
    int i,j;
    struct sf *temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]->p<x[j+1]->p)
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
}
void display(struct sf **x,int *slot,int *res,int n)
{
        int i;
        for(i=0;i<n;i++)
                if(slot[i])
                        printf("%c ",x[res[i]]->ch);
        printf("\n");
}
void seq(struct sf **x,int n)
{
    int i,j;
    int *slot,res[n];
    slot=(int*)calloc(n,sizeof(int));
    sort(x,n);
    for(i=0;i<n;i++)
    {
        for(j=min(x[i]->d,n)-1;j>=0;j--)
        {
                if(!slot[j])
                {
                        slot[j]=1;
                        res[j]=i;
                        break;
                }
        }
    }
    display(x,slot,res,n);
   
}
void main()
{
    int i,n;
    struct sf **s;
    printf("ENTER NUMBER OF JOBS: ");
    scanf("%d",&n);
    s=(struct sf**)malloc(n*sizeof(struct sf*));
    
    for(i=0;i<n;i++)
    {
        s[i]=(struct sf*)malloc(sizeof(struct sf));
        printf("ENTER CODE,DEADLINE AND PROFIT OF JOB %d :",(i+1));
        scanf("%s %d %d",&s[i]->ch,&s[i]->d,&s[i]->p);
    }
    printf("THE SEQUENCE OF DOING THE JOBS IS:\n");
    seq(s,n);
}
