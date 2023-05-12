#include<stdio.h>
#include<stdlib.h>
void accept(int*,int);
void i_sort(int*,int);
int bin_srch(int*,int,int,int);
void disp(int*,int);
int main()
{
	int *a,n;
	printf("Enter length of Array ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	accept(a,n);
	printf("\nBEFORE SORTING \n");
	disp(a,n);
	printf("\nAFTER SORTING \n");
	i_sort(a,n);
}
void accept(int *x,int y)
{
	int i;
	printf("Enter elements of Array\n");
	for(i=0;i<y;i++)
	{
		scanf("%d",&x[i]);
	}
}
void i_sort(int *x,int y)
{
	int i,j,k,l;
	for(i=1;i<y;i++)
	{
		j=i-1;
		k=x[i];
		l=bin_srch(x,0,y-1,k);
		while(j>=l)
		{
			x[j+1]=x[j];
			j--;
		}
		x[j+1]=k;
	}
	disp(x,y);
}
int bin_srch(int *x,int l,int r,int y)
{
	int mid;
	if(l>=r)
	return (y>x[l])?l+1:l;
	
	mid=(l+r)/2;
	
	if(y==x[mid])
	return mid+1;
	
	if(y>x[mid])
	return bin_srch(x,mid+1,r,y);
	
	if(y<x[mid])
	return bin_srch(x,l,mid-1,y);
}
void disp(int *x,int y)
{
	int i;
	for(i=0;i<y;i++)
		printf("%3d",x[i]);
}
