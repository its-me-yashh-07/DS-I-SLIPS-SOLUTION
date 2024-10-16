/*Slip_8_Q2. Write a C program to check whether the contents of two stacks are
 identical. Use stack library to perform basic stack operations. Neither
 stack should be changed.*/

 #include<stdio.h>
#include<process.h>
#define MAX 5
typedef struct stack
{
	int stk[MAX],top;
}STACK;
STACK init(STACK s)
{
	s.top = -1;
	return s;
}
int isfull(STACK s)
{
	if(s.top==MAX-1)
		return 1;	
	else
		return 0;
}
int isempty(STACK s)
{
	if(s.top==-1)
		return 1;
	else
		return 0;
}
STACK push(STACK s)
{
	if(isfull(s))
		printf("\n Stack is full");
	else
	{
		printf("\n Enter Element : ");
		scanf("%d",&s.stk[++s.top]);
	}
	return s;
}
int check(STACK s1, STACK s2)
{
	int i;
	
	if(s1.top!=s2.top)
		return 0;
	for(i=s1.top;i!=-1;i--)
		if(s1.stk[i]!=s2.stk[i])
			return 0;
	return 1;
}
int main()
{
	int ch,result;
	STACK s1,s2;
	printf("Enter element of stack 1 :");
	s1 = init(s1);
	s2 = init(s2);
	s1 = push(s1);
	s1 = push(s1);
	s1 = push(s1);
	printf("Enter element of stack 2 :");
	s2 = push(s2);
	s2 = push(s2);
	s2 = push(s2);
	result = check(s1,s2);
	if(result==1)
		printf("\n Stacks are identical");
	else
		printf("\n Stacks are not identical");
	return 0;
}
