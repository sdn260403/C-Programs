#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve(char *a,char *b,char *c,int i,int x,int n)
{
    a[i]=b[x];
    if(a[i]==c[0] || i>n)
        return;
    else
    {
        x+=1;
        solve(a,b,c,2*i,x,n);
    }
    x+=1;
    solve(a,b,c,2*i+1,x,n);
    if(a[i]==c[1])
       printf("%s",a);
}

int main()
{
    char pre[20],post[20],res[20];
    int n;

    printf("Enter prefix expression\n");
    scanf("%[^\n]",pre);
    pre[strlen(pre)-1]='\0';
    fflush(stdin);

    printf("Enter postfix expression\n");
    scanf("%[^\n]",post);
    /*post=*/
    post[strlen(post)-1]='\0';

    n=strlen(pre);
    //res[0]='j';
    res[1]=pre[1];
    solve(res,pre,post,2,2,n);
}
// ABDHIEJKCFLMGNO
// HIDJKEBLMFNOGCA