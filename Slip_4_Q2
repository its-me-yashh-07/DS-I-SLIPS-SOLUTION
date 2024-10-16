 /*Slip_4_Q2. Write a program to reverse the elements of a queue using queue library.
 Implement basic queue operations init, enqueue, dequeue. */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct que
{
	int queue[MAX];
	int front,rear;
}Q;
void init()
{
	Q.front = Q.rear = 0;
}
int isEmpty()
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}
int isFull()
{
	if(Q.rear==MAX)
		return 1;
	else
		return 0;
}
void enqueue()
{
	if(isFull())
		printf("\n Queue is Full");
	else
	{
		printf("\n Enter Element : ");
		scanf("%d",&Q.queue[Q.rear++]);
	}
}
void dequeue()
{
	if(isEmpty())
		printf("\n Queue is Empty");
	else
		printf("\n Deleted Element is : %d",Q.queue[Q.front++]);
}
void display()
{
	int i;
	if(isEmpty())
		printf("\n Queue is Empty");
	else
	{
		printf("\n Queue elements are : ");
		for(i=Q.front;i<Q.rear;i++)
			printf(" %d ",Q.queue[i]);
	}
}
void reverse()
{
	int i;
	int stk[5],top=-1;
	if(isEmpty())
		printf("\n Queue is Empty");
	else
	{
		for(i=Q.front;i<Q.rear;i++)
			stk[++top] = Q.queue[i];
		i=Q.front;
		while(top!=-1)
			Q.queue[i++] = stk[top--];
	}
}
int main()
{
	int ch;	
	init();
	while(ch!=5)
	{
		printf("\n 1) Insert");
		printf("\n 2) Delete");
		printf("\n 3) Display");
		printf("\n 4) Reverse");
		printf("\n 5) Exit");
		printf("\n Enter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue();
					break;
			case 2:	dequeue();
					break;
			case 3:	display();
					break;
			case 4:	reverse();
					break;
			case 5:	exit(0);
					break;
			default: printf("\n Invalid Choice");
		}
		display();
	}
}
