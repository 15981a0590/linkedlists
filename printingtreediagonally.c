#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node* right;
};
struct node* newnode(int data){
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
	}
struct node* insert(struct node* root,int *a,int i,int n){
	if(i<n){
		struct node* temp=newnode(a[i]);
		root=temp;
		if(a[2*i+1]!=0){
			root->left=insert(root->left,a,2*i+1,n);
		}
		else
		root->left=NULL;
		if(a[2*i+2]!=0){
			root->right=insert(root->right,a,2*i+2,n);
		}
		else
		root->right=NULL;
	}
	return root;
}
int front=-1,rear=-1;
void printdiagonal(struct node* root,int n){
	struct node** queue=(struct node**)malloc(n*sizeof(struct node*));
	struct node* temp=NULL;
	struct node* p;
	queue[++rear]=root;
	//++front;
	queue[++rear]=temp;
	while(front!=rear){
	p=queue[++front];
	if(p==NULL){
		queue[++rear]=temp;
		p=queue[++front];
		if(p==NULL)
		break;
	}
	while(p!=NULL){
	printf("%d ",p->data);
	if(p->left)
	queue[++rear]=p->left;
	p=p->right;

}
}
}
void inorder(struct node* root){
	if(!root)
	return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int main()
{
	int i,n;
	struct node* root=NULL;
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	root=insert(root,a,0,n);
	//inorder(root);
	printdiagonal(root,n);
	
	return 0;
}
