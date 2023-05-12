#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct BST
{
   int data;
   struct BST *lchild ;
   struct BST *rchild;
} node;

node* get_node(int d) //Get new Node
{
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->data=d;
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}

/*
 This function is for creating a binary search tree
 */
void insert(node *root, node *new_node)
{
   if (new_node->data < root->data)
   {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }
   else
   {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}

void inorder(node *temp)//INORDER
{
   if (temp != NULL)
   {
      inorder(temp->lchild);
      printf("%d >> ", temp->data);
      inorder(temp->rchild);
   }
}

void preorder(node *temp)//PRE ORDER 
{
   if (temp != NULL)
   {
   	  printf("%d >> ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}

void postorder(node *temp)//POST ORDER
{
   if (temp != NULL)
   {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d >> ", temp->data);
   }
}

int main()
{
	int d;
   char ans;
	struct BST *root=NULL,*new_node;
	
         do 
		 {
            
            printf("\nEnter The Element ");
            scanf("%d", &d);
            new_node = get_node(d);

            if (root == NULL)
               root = new_node;
            else
               insert(root, new_node);

            printf("\nWant To enter More Elements?(y/n)");
            ans = getche();
         } while (ans == 'y');
         printf("INORDER TRAVERSAL OF THE TREE IS:\n");
         inorder(root);
        
}
