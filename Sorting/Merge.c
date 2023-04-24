#include<stdio.h>
#include<stdlib.h>
void sort(int*,int,int);
void merge(int*,int,int,int);
void accept(int*,int);
void disp(int*,int);

int main()
{
	int *x,n;
	printf("ENTER NUMBER OF ELEMENTS ");
	scanf("%d",&n);
	x=(int*)malloc(sizeof(int)*n);
	accept(x,n);
	printf("\nBEFORE SORTING\n");
	disp(x,n);
	sort(x,0,n-1);
	printf("\nAFTER SORTING\n");
	disp(x,n);
	return 0;
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
void sort(int *a,int l,int r)
{
	int mid;
	if(l!=r)
	{
		mid=(l+r)/2;
		sort(a,l,mid);
		sort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
void merge(int *a,int l,int m,int r)
{
	int i,j,k=0,aux[100];
	for(i=l,j=m+1;i<=m,j<=r;)
	{
		if(a[i]>a[j])
		{
			aux[k]=a[j];
			k++;
			j++;
		}
		else
		{
			aux[k]=a[i];
			k++;
			i++;
		}
	}
	while(i<=m)
	{
		aux[k]=a[i];
		k++;
		i++;
	}
	while(j<=r)
	{
		aux[k]=a[j];
		k++;
		j++;
	}
	for(i=0;i<k;i++)
		a[l++]=aux[i];
}
void disp(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%3d",a[i]);
}
