#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) (a>b)?a:b
inline int hash(int);
void Linear_probing(int);
void change();
void del(int);
int search(int);
int nxtprime();
void fill();

struct lp
{
int *a,ts,n,m,c;
}s;


int main()
{
	s.ts=-1;
	s.c=0;
	int ch,key;
	printf("Enter number of elements: ");
	scanf("%d",&s.n);
	s.m=nxtprime(s.n);
	s.a=(int*)malloc(sizeof(int)*s.m);
	fill();

	printf("\n1 to insert\n2 to delete\n3 to search\n4 to exit");
	do
	{
		printf("\nEnter Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("ENTER ELEMENT: ");
					scanf("%d",&key);
					Linear_probing(key);
					if(s.c>1 && max(s.ts,key)==key)
					change(key+1);
					break;
			
			case 2: printf("ENTER ELEMENT TO BE DELETED: ");
					scanf("%d",&key);
					del(key);
					break;
			
			case 3: printf("ENTER ELEMENT TO BE SEARCHED: ");		
					scanf("%d",&key);
					int x=search(key);
					if(x==s.ts)
					printf("NOT FOUND");
					else
					printf("FOUND AT POSITION %d",(x+1));
					break;
			
		}
	}while(ch!=4);
}

void fill()
{
	int i=0;
	while(i<s.m)
	{
		s.a[i]=0;
		i+=1;
	}
}

inline int hash(int x)
{
	return (x%s.m);
}

int nxtprime(int x)
{
	int i,flag=1;
	while(1)
	{
		x+=1;
		for(i=2;i<=ceil(sqrt(x));i++)
		{
			if(x%i==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			return x;
		else
			flag=1;
	}
}

void Linear_probing(int k)
{
	int i;
	if(s.c>=s.m)
		printf("TABLE IS FULL...CANNOT ENTER ELEMENT");
	else
	{
		i=hash(k);
		while(s.a[i] != 0 || i>s.m)
			i=(i+1)%s.m;
		s.a[i]=k;
		s.c+=1;
	}
	
}

void change(int x)
{
	int i=0;
	while(i<s.m)
	{
		if(s.a[i]==s.ts)
		s.a[i]=x+1;
		i+=1;
	}
	s.ts=x+1;
}

void del(int x)
{
	int i=search(x);
	if(i!=s.ts)
	{
		s.a[i]=s.ts;
		s.c-=1;
	}
	else
		printf("ELEMENT TO BE DELETED NOT FOUND"); 
}

int search(int x)
{
	int i,j;
	i=hash(x);
	if(s.a[i]==x)
	return i;
	i+=1;
	j=hash(x);
	while(i!=j)
	{
		if(s.a[i]==x)
			return i;
		i=(i+1)%s.m;
	}
	return s.ts;
}

