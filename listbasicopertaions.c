#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* create(struct node* head,int data)
{
	struct node* temp=head;
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
		return  head;
	}
	else
	{
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=nn;
		return head;
	}
}
void print(struct node* root)
{
	while(root)
	{
		printf("%d-->",root->data);
		root=root->next;
	}
	printf("NULL");
}
struct node* inserttail(struct node* root,int data)
{
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	struct node* temp=root;
	if(temp==NULL)
	{
		temp=nn;
		return temp;
	}
	else
	{
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
	return root;
}
struct node* inserthead(struct node* head,int data)
{
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
		return head;
	}
	else
	{
		nn->next=head;
		head=nn;
	}
	return head;
}
struct node* insertposition(struct node* head,int pos,int data)
{
	struct node* temp=head;
	struct node* nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=NULL;
	if(pos==0)
	{
		nn->next=head;
		head=nn;
		return head;
	}
	else
	{
	for(int i=0;i<pos-1;i++)
	{
		temp=temp->next;
	}
	nn->next=temp->next;
	temp->next=nn;
	
	return head;
}
}
int main()
{
	struct node* root=NULL;
	int n,k,i,pos;
	printf("enter the size of list:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter %d element : ",i+1);
		scanf("%d",&k);
	root=create(root,k);
}
print(root);
printf("\nafter inserting 12 insert an element at tail\n");
root=inserttail(root,12);
print(root);
printf("\nafter inserting 10 insert an element at front\n");
root=inserthead(root,10);
print(root);
printf("\nafter 11 inserting at specific position \n");
printf("\n enter the position\n");
scanf("%d",&pos);
root=insertposition(root,pos,11);
print(root);
return 0;
}

