/*Construction of Expression Tree: 

Now For constructing an expression tree we use a stack. We loop through input expression and do the following for every character. 

If a character is an operand push that into the stack
If a character is an operator pop two values from the stack make them its child and push the current node again.
In the end, the only element of the stack will be the root of an expression tree.
ABC*+D/
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dl
{
    struct dl *l,*r,*n;
    char d;
};
struct dl* newNode(int x)
{
    struct dl *temp;
    temp=(struct dl*)malloc(sizeof(struct dl));
    temp->d=x;
    temp->l=NULL;
    temp->r=NULL;
    temp->n=NULL;
    return temp;
}
void push(struct dl **head,struct dl *x)
{
    if(head==NULL)
        *head=x;
    else
    {
        x->n=*head;
        *head=x;
    }
}
struct dl* pop(struct dl **head)
{
    struct dl *p=*head;
    *head =p->n;
    return p;
}
void display(struct dl *f)
{
    if(f!=NULL)
    {
        printf("%c ",f->d);
        display(f->l);
        display(f->r);
    }
}
void create(char *s,int n)
{
    int i;
    struct dl *head,*e1,*e2,*temp;
    for(i=0;i<n;i++)
    {
        if (s[i] != '+' && s[i] != '-' && s[i] != '*'&& s[i] != '/' && s[i] != '^')
        {
            temp=newNode(s[i]);
            push(&head,temp);
        }
        else
        {
            e1=pop(&head);
            e2=pop(&head);
            temp=newNode(s[i]);
            temp->l=e1;
            temp->r=e2;
            push(&head,temp);
        }
    display(temp);     
    }
}


int main()
{
    int n;
    char str[100];
    printf("ENTER EXPRESSION\n");
    fflush(stdin);
    gets(str);
    n=strlen(str);
    str[strlen(str)]='\0';
    printf("%s",str);
    create(str,n);
}
