#include<stdio.h>
#include<stdlib.h>
struct sf
{
    int st,fi;
};
void sort(struct sf **x,int n)
{
    int i,j;
    struct sf *temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]->fi>x[j+1]->fi)
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
}
void activity(struct sf **x,int n)
{
    int i,j;
    sort(x,n);
    j=0;
    printf("(%d,%d) ",x[j]->st,x[j]->fi);
    for(i=1;i<n;i++)
    {
        if(x[i]->st>=x[j]->fi)
        {
            printf("(%d,%d) ",x[i]->st,x[i]->fi);
            j=i;
        }
    }
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
        printf("ENTER START AND FINISH TIME OF JOB %d : ",(i+1));
        scanf("%d %d",&s[i]->st,&s[i]->fi);
    }
    printf("THE SEQUENCE OF DOING THE TASKS IS:\n");
    activity(s,n);
}
