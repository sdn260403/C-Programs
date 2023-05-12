

#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
#define MAX 50

struct node
{
        struct node *lchild;
        int info;
        struct node *rchild;
};

struct node *insert_nrec(struct node *root, int ikey );
void nrec_pre(struct node *root);
void nrec_in(struct node *root);
void nrec_post(struct node *root);

struct node* stack[MAX];
int top=-1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();
int height(struct node *root,int c)
{
	if(root->lchild ==NULL)
		return c;
	return max(height(root->lchild,c+1),height(root->rchild,c+1));
}
int main( )
{
        struct node *root=NULL, *ptr;
        int choice,k;
	printf("\n");
        printf("1.Insert\n");
        printf("2.Preorder \n");
        printf("3.Inorder \n");
        printf("4.Postorder\n");
        printf("5.Height\n");
        printf("6.Quit\n");

        while(1)
        {
                
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nEnter value : ");
                        scanf("%d",&k);
                        root = insert_nrec(root, k);
                        break;


                case 2:
                        nrec_pre(root);
                        break;

                case 3:
                        nrec_in(root);
                        break;

                case 4:
                        nrec_post(root);
                        break;

                case 5:
                        printf("Height is: %d",height(root,1));
                        break;
                case 6:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }
	}
        return 0;

}

struct node *search_nrec(struct node *ptr, int skey)
{
        while(ptr!=NULL)
        {
                if(skey < ptr->info)
                        ptr = ptr->lchild; 
                else if(skey > ptr->info)
                        ptr = ptr->rchild;  
                else    
                        return ptr;
        }
        return NULL;
}

struct node *insert_nrec(struct node *root, int ikey)
{
        struct node *tmp,*par,*ptr;

        ptr = root;
        par = NULL;

        while( ptr!=NULL)
        {
                par = ptr;
                if(ikey < ptr->info)
                        ptr = ptr->lchild;
                else if( ikey > ptr->info )
                        ptr = ptr->rchild;
                else
                {
                        printf("\nDuplicate key");
                        return root;
                }
        }

        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lchild=NULL;
        tmp->rchild=NULL;

        if(par==NULL)
                root=tmp;
        else if( ikey < par->info )
                par->lchild=tmp;
        else
                par->rchild=tmp;

        return root;
}




void nrec_pre(struct node *root)
{
        struct node *ptr = root;
        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        push_stack(ptr);
        while( !stack_empty() )
        {
                ptr = pop_stack();
                printf("%d  ",ptr->info);
                if(ptr->rchild!=NULL)
                        push_stack(ptr->rchild);
                if(ptr->lchild!=NULL)
                        push_stack(ptr->lchild);
        }
        printf("\n");
}

void nrec_in(struct node *root)
{
        struct node *ptr=root;

        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        while(1)
        {
                while(ptr->lchild!=NULL)
                {
                        push_stack(ptr);
                        ptr = ptr->lchild;
                }

                while( ptr->rchild==NULL)
                {
                        printf("%d  ",ptr->info);
                        if(stack_empty())
                                return;
                        ptr = pop_stack();
                }
                printf("%d  ",ptr->info);
                ptr = ptr->rchild;
        }
        printf("\n");
}

void nrec_post(struct node *root)
{
        struct node *ptr = root;
        struct node *q;

        if( ptr==NULL )
        {
                printf("Tree is empty\n");
                return;
        }
        q = root;
        while(1)
        {
                while(ptr->lchild!=NULL)
                {
                        push_stack(ptr);
                        ptr=ptr->lchild;
                }

                while( ptr->rchild==NULL || ptr->rchild==q )
                {
                        printf("%d  ",ptr->info);
                        q = ptr;
                        if( stack_empty() )
                                return;
                        ptr = pop_stack();
                }
                push_stack(ptr);
                ptr = ptr->rchild;
        }
        printf("\n");
}


void push_stack(struct node *item)
{
        if(top==(MAX-1))
        {
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}

struct node *pop_stack()
{
        struct node *item;
        if(top==-1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        item=stack[top];
        top=top-1;
        return item;
}

int stack_empty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}


