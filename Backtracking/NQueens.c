#include<stdio.h>
#include<stdlib.h>
typedef struct prop
{
    int n,*b;
}p;
void print(p s,int n)
{
    int i,j;
    printf("\n\nSolution %d Queens:\n\n",s.n); 
    for(i=1;i<=s.n;++i)
        printf("\t%d",i);
 
    for(i=1;i<=s.n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=s.n;++j) 
        {
            if(s.b[i]==j)
                printf("\tQ"); 
            else
                printf("\t_");
        }
    }
}
int check(int i,p *s,int x,int y)
{
    if(i==x)
        return 1;
    if(s->b[i]==y)
        return 0;
    if(abs(s->b[i]-y)==abs(i-x))
        return 0;
    return check(i+1,s,x,y);
}

void queen(p s,int r)
{
    int i;
    for(i=1;i<=s.n;i++)
    {
        if(check(1,&s,r,i))
        {
            s.b[r]=i;
            if(r==s.n)
            {
                print(s,s.n);
                exit(0);
            }
            else
                queen(s,r+1);
        }
    }
}

int main()
{
p s;
printf("\n\nEnter number of Queens:");
scanf("%d",&s.n);
s.b=(int*)malloc(sizeof(int)*(s.n+1));
queen(s,1);
return 0;
}
