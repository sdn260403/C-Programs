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
        if(left>right)
                return;
        int i=left,j=right;
       
        while(i<j)
        {
                while(a[i]<=a[left])
                        i+=1;
                while(a[j]>a[left])
                        j-=1;
                if(i<j)
                        swap(a,i,j);               
        }
        swap(a,j,left);
        sort(a,left,j-1);
        sort(a,j+1,right);
}

void disp(int *a,int n)

{

	int i;

	for(i=0;i<n;i++)

	printf("%3d",a[i]);

}
