#include<stdio.h>
#include<stdlib.h>
struct req
{
    char *txt,*pat;
    int *lps;//longest suffix prefix.
    int nt,np,flag=0;
};
void fill_lps(struct req*);
void kmp(struct req);
void main()
{
    struct req s;
    printf("ENTER LENGTH OF STRING AND PATTERN: ");
    scanf("%d %d",&s.nt,s.np);
    printf("ENTER STRING AND PATTERN: ");
    scanf("%[^\n]s",s.txt);
    scanf("%[^\n]s",s.pat);
    s.lps=(int*)malloc(sizeof(int)*s.np);
    fill_lps(&s);
    kmp(s);
}
void fill_lps(struct req *x)
{
    int i=1,l=0;
    x->lps[0]=0;
    while(i<x->np)
    {
        if(x->pat[i]==x->pat[l])
        {
            l++;
            x->lps[i]=l;
            i++;
        }
        else
        {
            if(l!=0)
                l=x->lps[l-1];
            else
            {
                x->lps[i]=0;
                i++;
            }
        }
    }
}
void kmp(struct req x)
{
    int i=0,j=0;
    while((x.nt-i)>=(x.np-j))
    {
        if(x.txt[i]==x.pat[j])
        {
            i++;
            j++;
        }
        if(j==x.np)
        {
            printf("FOUND PATTERN AT INDEX %d\n",i-j);
            j=x.lps[j-1];
            x.flag=1;
        }
        else 
        {
            if(i<x.nt && x.pat[j]!=x.txt[i])
            {
                if(j!=0)
                    j=x.lps[j-1];
                else
                    i++;
            }
        }
    }
    if(x.flag==0)
        printf("NO MATCHING STRING PRESENT\n");
}