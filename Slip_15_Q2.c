/*Slip_15_Q2. Implement a linear queue library (dyqueue.h) of integers using a dynamic
(circular linked list) implementation of the queue and implementing the
five queue operations (init(Q), AddQueue(Q, x), X=DeleteQueue(Q),
X=peek(Q), isEmpty(Q)).
Write a program to reverse the elements of a queue using queue library.*/


//(Program File : ) (cir_queue.c File)

 #include<stdio.h> 
#include "cir_queue.h" 
main() 
{ int ch,no; 
 init(); 
 do 
 { 
  printf("\n1.Add \n2.Delete \n0.Exit"); 
  printf("Enter choice"); 
  scanf("%d",&ch); 
  switch(ch) 
  { 
   case 1:printf("\n Enter element"); 
     scanf("%d",&no); 
     Add(no); 
     break; 
   case 2:if(isempty()==1) 
     printf("\n Queue is empty"); 
     else 
      { 
       printf("deleted 
element is %d",Delete()); 
       break; 
 
      } 
   case 0:break; 
   case 4:printf("Elemenent at peek %d ",peek()); 
     break; 
   default:printf("Invalid choice");     
  } 
 }while(ch!=0); 
  
}



//(Header File : cir_queue.h )

#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
int data; 
struct node *next; 
}; 
struct node *r; 
void init() 
{ 
r=NULL; 
} 
int isempty() 
{ 
if(r==NULL) 
return 1; 
else 
return 0;  
} 
void Add(int n) 
{ 
struct node *nw; 
nw=(struct node *)malloc(sizeof(struct node)); 
nw->data=n; 
if(r==NULL) 
{ 
r=nw; 
r->next=r; 
} 
else 
{ 
nw->next=r->next; 
r->next=nw; 
r=r->next; 
} 
} 
int Delete() 
{ 
int no; 
struct node *temp; 
temp=r->next; 
if(r==temp->next) 
{ 
r=NULL; 
} 
else
{ 
  r->next=temp->next; 
 } 
 no=temp->data; 
 free(temp); 
 return (no); 
} 
int peek() 
{ 
 return r->next->data; 
} 
