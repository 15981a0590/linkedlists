#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int top=-1;
void push(int* stack,int data)
{
	if (top==MAXSIZE-1)
	   printf("\n stack is empty");
	stack[top++]=data;
}
int pop(int* stack)
{
	return stack[top--];
}
void display(int* stack)
{
	int i;
	if(top==-1)
	printf("stack is empty\n");
	for(i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
}
}
int main()
{
	int stack[100],data,ch;
	
	do
	{
		printf("\n choose following operations :\n1.push \n2.pop\n3.dispaly\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the data you want to push into stack");
			      scanf("%d",&data);
			      push(stack,data);
			      break;
			case 2:printf("\n you poped the data item %d :",pop(stack));
			      break;
			case 3:printf("\nthe stack elements are:"); 
			      display(stack); 
			      break;  
			case 4:printf("\n you are exiting from the program");
			      exit(0);
			      break; 
			default:printf("\n choose the proper option");
			                          
		}
	}while(1);
	return 0;
}
