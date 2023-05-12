#include<stdio.h>
#include<stdlib.h>
void disp(int arr[], int N)
{
	int i;
    for (i = 1; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *a,int n,int i)
{
    int r=i,lt=2*i,rt=2*i+1;

    if(lt<n && a[lt] > a[r])
    r=lt;

    if(rt<n && a[rt] > a[r])
    r=rt;

    if(r!=i)
    {
        swap(&a[i],&a[r]);
        heapify(a,n,r);
    }
}
void heapSort(int *a,int n)
{
    int i;
    for(i=n-1;i>=1;i--)
        heapify(a,n,i);

    for(i=n-1;i>=1;i--)
    {
        swap(&a[1],&a[i]);
        heapify(a,i,1);
        
    }
}


 
int main()
{
    int *a,i=1,y;
    printf("ENTER LENGTH OF ARRAY: ");
    scanf("%d",&y);
	y+=1;
	a=(int*)malloc(sizeof(int)*y);
    while(i<y)
	{
		printf("ENTER A NUMBER : ");
		scanf("%d",&a[i]);
		i++;
	}
    heapSort(a, y);
    printf("Sorted array is\n");
    disp(a, y);
}