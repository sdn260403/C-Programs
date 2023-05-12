#include <stdio.h>
void Accept(int[]);
void Insertion_Sort(int[]);
void display(int[]);
main()
{
	int a[10];
	Accept(a);
	Insertion_Sort(a);
}
void Accept(int x[])
{
	int i=0;
	printf("ENTER ELEMENTs :-\n");
	while(i<10)
	{
		scanf("%d",&x[i]);
		i+=1;
	}
}
void Insertion_Sort(int x[])
{
	int i,k,p;
	for(i=1;i<10;i++)
	{
		k=x[i];
		p=i-1;
		while(x[p]>k&&p>=0)
		{
			x[p+1]=x[p];
			p=p-1;
	    }
	    x[p+1]=k;
	}
	display(x);
}
void display(int x[])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("\n %d",x[i]);
	}
}
