#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
void push(int* s,int data,int top)
{
	s[top++]=data;
}
int pop(int* s,int top)
{
	return s[top--];
}
struct node* newnode(int dat)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=dat;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void inorder(struct node* root)
{
	if(!root)
	   return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	
}
void preorderwithoutrecursion(struct node* root)
{
	struct node* stack[100];
	int top=-1;
	if(root==NULL)
	  return NULL;
	  stack[top++]=root;
	 while(top!=-1)
	 {
		root=stack[top--];
		printf("%d ",root->data);
		if(root->right)
		stack[top++]=root->right;
		if(root->left)
		stack[top++]=root->left;
		
	 }
}
int main()
{
	struct node* root=newnode(10);
	 root->left=newnode(11);
		 root->right=newnode(9);
		 root->left->left=newnode(7);
		root->right->right=newnode(8);
		root->right->left=newnode(15);
		//inorder(root);
		preorderwithoutrecursion(root);
		
		
return 0;
	}

