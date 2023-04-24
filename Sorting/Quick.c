#include<stdio.h>

#include<stdlib.h>

void sort(int*,int,int);

void accept(int*,int);

void disp(int*,int);

void swap(int*x,int i,int j)

{

	int t=x[i];
	x[i]=x[j];

	x[j]=t;

}

int main()

{

	int *a,n;

	printf("ENTER NUMBER OF ELEMENTS ");

	scanf("%d",&n);

	a=(int*)malloc(sizeof(int)*n);

	accept(a,n);

	printf("\nBEFORE SORTING\n");

	disp(a,n);

	sort(a,0,n-1);

	printf("\nAFTER SORTING\n");

	disp(a,n);

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

void sort(int*a,int left,int right)

{

	int i,last;

	if(left>=right)

	return;

	last = left;

	swap(a,left,(left+right)/2);

	for(i=left+1;i<=right;i++)

		if(a[left]>a[i])

			swap(a,++last,i);

	swap(a,last,left);

	sort(a,left,last-1);

	sort(a,last+1,right);	

}

void disp(int *a,int n)

{

	int i;

	for(i=0;i<n;i++)

	printf("%3d",a[i]);

}
