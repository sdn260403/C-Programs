#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
struct node
{
    int d;
    struct node *l,*r;
};
int height(struct node*);
int bal(struct node*);
void disp(struct node*);
struct node* get(int);
struct node* L_R(struct node*);
struct node* R_R(struct node*);
struct node* insert(struct node*,int);
int main()
{
    char ch;
    int d;
    struct node *root=NULL;
    do
    {
        printf("\nENTER VALUE: ");
        scanf("%d",&d);
        root=insert(root,d);
        printf("ENTER [Y] TO CONTINUE N TO EXIT");
        ch=getche();
    } while (ch!='n');
    printf("\n");
    disp(root);
    return 0;
}

struct node* get(int d)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->d=d;
    temp->r=NULL;
    temp->l=NULL;
    return (temp);
}
int height(struct node *x)
{
    if(x==NULL)
        return 0;
    return 1+max(height(x->r),height(x->l));
}
struct node* L_R(struct node* x)
{
    struct node *r,*t;
    r=x->r;
    t=r->l;
    r->l=x;
    x->r=t;

    return r;
}
struct node* R_R(struct node* x)
{
    struct node *r,*t;
    r=x->l;
    t=r->r;
    r->r=x;
    x->l=t;
    
    return r;
}
int bal(struct node *x)
{
    if(x==NULL)
        return 0;
    return height(x->l)-height(x->r);
}
void disp(struct node *x)
{
    if(x!=NULL)
    {
        disp(x->l);
        printf("%d ",x->d);
        disp(x->r);
    }
}

struct node* insert(struct node* root,int d)
{
    
    if(root==NULL)
        return (get(d));

    if(root->d < d)
        root->r= insert(root->r,d);
    else if(root->d>d)
        root->l= insert(root->l,d);
    else
        return root;

    int b=bal(root);
    if(b>1)
    {
        if(root->l->d>d)
            return R_R(root);
        else
        {
            root->l=L_R(root);
            return R_R(root);
        }
    }
    if(b<-1)
    {
        if(root->r->d<d)
            return L_R(root);
        else
        {
            root->r=R_R(root);
            return L_R(root);
        }
    }
    return root;
}