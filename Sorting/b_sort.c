#include<stdio.h>
#define MAX 100
void accept(int[],int);
void sort(int[],int);
void disp(int[],int);
int main()
{
	int a[MAX],n,ch;
	printf("Enter length of Array : ");
	scanf("%d",&n);
	accept(a,n);
	printf("\nBEFORE SORTING\n");
	disp(a,n);
	printf("\nAFTER SORTING\n");
	sort(a,n);
	disp(a,n);
}
void sort(int x[MAX],int y)
{
	int i,j,t;
	for(i=0;i<y;i++)
	{
		for(j=0;j<y-i-1;j++)
		{
			if(x[j]>x[j+1])
			{
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
}
void accept(int x[MAX],int y)
{
	int i;
	printf("ENTER %d NO. ELEMENTS:\n",y);
	for(i=0;i<y;i++)
		scanf("%d",&x[i]);
}
void disp(int x[MAX],int y)
{
	int i;
	for(i=0;i<y;i++)
		printf("%4d",x[i]);
}
