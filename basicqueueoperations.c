#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
int front=-1,rear=-1;
void display(int* queue)
{
	if(front==rear)
	{
		printf("\nqueue is empty");
	}
	else
	{
	for(int i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
}
}
void enqueue(int* queue,int data)
{
	if(rear==MAXSIZE-1)
	printf("\n queue is full\n");
	queue[rear++]=data;
}
int dequeue(int* queue)
{
	if(rear==front)
	printf("\n queue is empty\n");
	return queue[front++];
}

int main()
{
	int queue[100],data,ch;
	
	do
	{
		printf("\n choose following operations :\n1.enqueue \n2.dequeue\n3.dispaly\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the data you want to push into stack\n");
			      scanf("%d",&data);
			      enqueue(queue,data);
			      break;
			case 2:printf("\n you poped the data item %d :\n",dequeue(queue));
			      break;
			case 3:printf("\nthe stack elements are:\n"); 
			      display(queue); 
			      break;  
			case 4:printf("\n you are exiting from the program\n");
			      exit(0);
			      break; 
			default:printf("\n choose the proper option");
			                          
		}
	}while(1);
	return 0;
}
