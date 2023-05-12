#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int key;
    struct node *left, *right;
};
int *a;
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int key)
{
    
    if (node == NULL)
        return newNode(key);
 
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
void heapify(struct node* root,int i,int x)
{
	if(root->left != NULL || root->right)
	{
	a[i]=root->key;
	a[2*i]=root->left->key;
	a[2*i+1]=root->right->key;
	if(2*i+1==x-1)
	return;
	heapify(root->left,i+1,x);
	i+=1;
	heapify(root->right,i+1,x);
	}
}
void inorder(struct node* root)
{
    if (root != NULL) 
	{
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void in_heap(int i,int x)
{
	if(i<=x-1)
	{
		in_heap(2*i,x);
		printf("%d ",a[i]);
		in_heap(2*i+1,x);
	}
}
int main()
{
    /* create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
	*/
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 	int i,c=8;
 	a=(int*)malloc(sizeof(int)*c);
 	heapify(root,1,c);
 	printf("\nHEAPIFIED TREE \n");
 	for(i=1;i<c;i++)
 	{
 		printf("%d  ",a[i]);
	}
    printf("\nInorder traversal of the given tree \n");
    inorder(root);
    
    printf("\nInorder traversal of the given heapified tree \n");
    in_heap(1,c);
 
    return 0;
}
