#include<stdio.h>
#include<stdlib.h>
#define mini(a,b) (a<b)?a:b
int f(int i,int j,int *a,int **dp)
{
        if(i>=j)
                return 0;
        int k,t,m=999999999,p=1;
        if(dp[i][j]!=-1)
                return dp[i][j];
        for(k=i;k<j;k++)
        {
                t=(a[i-1]*a[j]*a[k])+f(i,k,a,dp)+f(k+1,j,a,dp);
                m=mini(m,t);
        }
        dp[i][j]=m;
        return m;
}
void main()
{
        int *a,i,j,n,**dp;
        printf("Enter number of elements : ");
        scanf("%d",&n);
        a=(int*)calloc(n,sizeof(int));
        dp=(int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++)
        {
                printf("ENTER ELEMENT %d : ",(i+1));
                scanf("%d",&a[i]);
                dp[i]=(int*)malloc(n*sizeof(int));
                for(j=0;j<n;j++)
                        dp[i][j]=-1;
        }
        printf("MINIMUM NUMBER OF MULTIPLICATIONS ARE : %d\n ",f(1,n-1,a,dp));
}
