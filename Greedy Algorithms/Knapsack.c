#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
struct ratio
{
	int value;
	int weight;
	float r;
};
void b_sort(struct ratio **a,int n)
{
	int i,j;
	struct ratio temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]->r<a[j+1]->r)
			{
				temp=*a[j];
				*a[j]=*a[j+1];
				*a[j+1]=temp;
			}
		}
	}
}
float fractional_knapsack(struct ratio **a,int n,int W)
{
	b_sort(a,n);
	int i;
	float ans=0.0;
	for(i=0;i<n;i++)
	{
		if(a[i]->weight<=W)
		{
			ans+=a[i]->value;
			W-=a[i]->weight;
		}
		else
		{
			ans+=W*a[i]->r;
			break;
		}	
	}
	return ans;
}
int k01(struct ratio **a,int i,int **dp,int w)
{
	int t,nt=0;
	if(dp[i][w]!=-1)
		return dp[i][w];
	if(i==0)
		if(a[i]->weight<=w)
			return a[i]->value;
		else 
			return 0;
	nt=k01(a,i-1,dp,w);
	t=-999;
	if(a[i]->weight<=w)
		t=a[i]->value+k01(a,i-1,dp,(w-a[i]->weight));
	return dp[i][w]=max(t,nt);
	
}
void main()
{
	struct ratio **a;
	int i,j,n,W,**dp;
	printf("ENTER NUMBER OF OPTIONS AND CAPACITY OF KNAPSACK: ");
	scanf("%d %d",&n,&W);
	a=(struct ratio**)calloc(n,sizeof(struct ratio*));
	dp=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{
		dp[i]=(int*)malloc((W+1)*sizeof(int));
		for(j=0;j<W+1;j++)
			dp[i][j]=-1;
	}
	for(i=0;i<n;i++)
	{
		a[i]=(struct ratio*)calloc(1,sizeof(struct ratio));
		printf("ENTER VALUE AND WEIGHTAGE : ");
		scanf("%d %d",&a[i]->value,&a[i]->weight);
		a[i]->r=(float) a[i]->value/a[i]->weight;
	}
	printf("ANSWER OF 0/1 KNAPSACK: %d\nANSWER OF FRACTIONAL KNAPSACK: %f\n",k01(a,n-1,dp,W),fractional_knapsack(a,n,W));
}
