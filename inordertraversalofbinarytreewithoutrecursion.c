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
void inorderwr(struct node* root)
{
	
	int top=-1;
	struct node* stack[100];
	while(1)
	{
		if(root)
		{
			stack[top++]=root;
			root=root->left;
		}
		else 
		{
			if(top==-1)
			{
				break;
			}
			root=stack[--top];
			printf(" %d ",root->data);
            
			root=root->right;
		}
		
	}
	//printf("%d",top);
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
		inorderwr(root);
		
		
return 0;
	}
