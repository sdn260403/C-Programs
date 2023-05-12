#include <stdio.h>
#include <stdlib.h>
struct stack
{
char c[100];//EXPRESSION ARRAY
char a[100];//OPERATOR STACK
char n[100];//POSTFIX EXPRESSION
int top;
}s;
inline int check(char);
int pref(char);
void push(char);
char pop();
int main()
{
int i=0,x=0;
s.top=-1;
    printf("Enter expression  ");
    scanf("%[^\n]",&s.c);
    while(s.c[i]!='\0')
    {
    if(check(s.c[i])==1)
    {
    if (s.c[i]=='(')	
	push(s.c[i]);
	else if(s.c[i]==')')
    {
    while(s.a[s.top]!='(')
   	s.n[x++]=pop();
    s.top-=1;
	}
    else    
	{
      while(s.top>=0 && pref(s.c[i])<=pref(s.a[s.top]))
      s.n[x++]=pop();
      push(s.c[i]);
    }  
    }
        else
        {
        s.n[x++]=s.c[i];
       }
    i+=1;
   	}
while(s.top!=-1)
{
s.n[x++]=pop();
}
s.n[x]='\0';
puts(s.n);

}
inline int check(char x)
{
return (x>=65&&x<=90||x>=97&&x<=122)?0:1;
}
int pref(char x)
{
switch(x)
{
case '^':return 3;
case '/':
case '%':
case '*':return 2;
case '+':
case '-':return 1;
default:return -1;
}
}
char pop()
{
char x=s.a[s.top];
s.top-=1;
return x;
}
void push(char x)
{
s.top+=1;
s.a[s.top]=x;
}
