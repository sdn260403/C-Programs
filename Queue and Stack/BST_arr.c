#include<stdio.h>
#include<stdlib.h>
int* fill(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=0;
    return a;
}

void insert(int **a,int key,int i)
{
    if(*(*a+i)==0)
    {
        *(*a+i)=key;
    }
        

    if(*(*a+i)<key)
        insert(a,key,2*i+1);

    if(*(*a+i)>key)
        insert(a,key,2*i);
}

int minVal(int *a,int i,int n)
{
    if(2*i>n)
        return a[i];
    
    minVal(a,2*i,n);
}

void del(int **a,int key,int i,int n,int ts)
{
    if(i>n)
    {
        printf("ELEMENT NOT FOUND\n");
        return;
    }

    if(key>*(*a+i))
        del(a,key,2*i+1,n,ts);
    
    if(key<*(*a+i))
        del(a,key,2*i,n,ts);

    if(key==*(*a+i))
    {
        if(i>(int)(n/2))
            *(*a+i)=ts;
        else
        {
            int temp=*(*a+i);
            *(*a+i)=minVal(*a,2*i+1,n);
            del(a,temp,2*i+1,n,ts);
        }
    }
}

void search(int *a,int key,int i,int ts,int n)
{
    if(key>=ts || i>n)
    {
        printf("ELEMENT NOT PRESENT \n");
        return;
    }
    else
    {
    if(key==a[i])
        printf("ELEMENT PRESENT \n");

    if(key > a[i])
        search(a,key,2*i+1,ts,n);

    if(key < a[i])
        search(a,key,2*i,ts,n);
    }
}

void main()
{
    int n,i,ts,*a,x,ch;
    printf("ENTER LENGTH OF TREE : ");
    scanf("%d",&n);
    n+=1;
    a=(int*)malloc(sizeof(int)*(n));
    a=fill(a,n);
    for(i=1;i<n;i++)
    {
        printf("ENTER ELEMENT : ");
        scanf("%d",&x);
        insert(&a,x,1);
    }
    ts=a[n-1]+1;
    printf("\n1 to DELETE\n2 to SEARCH\n0 to exit");
 	do
 	{
 		printf("\nEnter Choice : ");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			
 			case 1:printf("Enter data to be deleted : ");
 				   scanf("%d",&x);
				   del(&a,x,1,n,ts);
 				   break;
            case 2:printf("Enter data to be searched : ");
 				   scanf("%d",&x);
				   search(a,x,1,ts,n);
 				   break;
 			
		 }
	 }while(ch!=0);
}