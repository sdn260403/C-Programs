#include <stdio.h>
#include <math.h>
#include <string.h>
struct stack
{
char c[100];//EXPRESSION ARRAY
int a[100];//OPERATOR STACK
int top;
}s;
int op(int,int,char);
inline int convert(char);
inline int isop(char);
void push(int);
void pop();
int main()
{
int i=0,s1=0,s2=0;
s.top=-1;
    printf("Enter expression\n");
    gets(s.c);
    while(s.c[i]!='\0')
    {
    if(isop(s.c[i])==0 && s.c[i]!=',' && s.c[i]!='#')
       s1=s1*10+convert(s.c[i]);
    else if(isop(s.c[i-1])==0 &&(s.c[i]==','||s.c[i]=='#'))
    {
      push(s1);
      s1=0;
    }
    else
    {
    s2=op(s.a[s.top-1],s.a[s.top],s.c[i]);
    pop();pop();
    push(s2);
    s2=0;i++;
	}
    i+=1;
    }
    printf("\n%d",s.a[s.top]);
}

inline int convert(char x)
{
return x-48;
}

inline int isop(char x)
{
return (x=='/'||x=='*'||x=='+'||x=='-'||x=='^')?1:0;
}

int op(int x,int y,char z)
{
switch(z)
{
case '/':return x/y;
case '*':return x*y;
case '+':return x+y;
case '-':return x-y;
case '^':return pow(x,y);
}
}

void pop()
{
s.top-=1;
}
void push(int x)
{
s.top+=1;
s.a[s.top]=x;
}
