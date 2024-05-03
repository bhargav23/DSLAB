#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
};
struct node* createNode(struct node*,int d){
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->right=NULL;
	temp->left=NULL;
	temp->data=d;
	return temp;
}
struct node * insert(struct node *root,int d){
	if(root==NULL){
		return createNode(root,d);
	} else { 
		if(d<root->data)	
			root->left = insert(root->left,d);
		else if(d>root->data)
				root->right=insert(root->right,d);
	}
	return root;
}
void inorder(struct node *root){
	if(root->left!=NULL)
		inorder(root->left);
	printf("%d ",root->data);
	if(root->right!=NULL)
		inorder(root->right);
}
void preorder(struct node *root){
	printf("%d ",root->data);
	if(root->left!=NULL)
		preorder(root->left);
	if(root->right!=NULL)
		preorder(root->right);
}
void postorder(struct node *root){
	if(root->left!=NULL)
		postorder(root->left);
	if(root->right!=NULL)
		postorder(root->right);
	printf("%d ",root->data);
}
int main(){
	struct node *root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,15);
	root=insert(root,5);
	inorder(root);
	printf("\n");
	printf("Preorder : ");
	preorder(root);
	printf("\n");
	printf("Postorder : ");
	postorder(root);
}
