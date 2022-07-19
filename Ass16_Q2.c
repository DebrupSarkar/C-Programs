/*NAME=DEBRUP SARKAR,ROLL NUMBER=54,CSE 
  ASSIGNMENT 16
  Q1>WRITE A MENU DRIVEN PROGRAM IN C TO IMPLEMENT LINEAR QUEUE USING ARRAY AND LINKED LIST. THE OPERATIONS ARE AS ENQUEUE(TO INSERT AN ELEMENT),DEQUEUE(REMOVING THE FRONT ITEM) AND DISPLAY*/
  
#include <stdio.h>
#include<cnio.h> 
int A[10], front=-1, rear=-1; // Creating Queue
int size_A = sizeof(A)/sizeof(A[0]); // Calculating Size of Array Dynamically
typedef struct Node
{
	int data;
	struct Node *link;
}node;
 
node *head=NULL;		// Head node to keep track of list
 
int IsEmpty()
{
	if(rear==-1 && front==-1)
		return 1;
	else
		return 0;
}
 
void EnQueue1(int data)
{
	if(IsEmpty())
		front = rear = 0;
	else if( rear+1 == front )
		printf("\n Queue is Full \n");
	else
		rear = (rear+1)%size_A;
	A[rear] = data;
}
 
int DeQueue1()
{
	if(IsEmpty())
		printf("\n Queue is Empty \n");
	else
		front = (front+1)%size_A;
	return A[front-1];
}
 
void Display1()
{
	int i=0;
	for(i=front;i<=rear;i++)
		printf(" %d",A[i]);
}
void EnQueque2(int data)
{
	// Declaring node
	node *temp = (node*)calloc(1,sizeof(node));
	temp->data = data;
	temp->link = NULL;
	
	// If head is NULL or first node
	if(!head)
	{
		head = temp;
		return;
	}
	node *traverse=head;
	
	// Traverse list upto end
	while(traverse->link)
		traverse = traverse->link;
	
	traverse->link = temp;
}
 
/* Delete Element */
int DeQueue2()
{
	node* temp = head;
	head = head->link;
	
	int data = temp->data;
	
	free(temp);
	
	return data;
}
 
/* Print queue */
void display2(node *p)
{
	printf(" %d",p->data);
	if(!p->link)
		return;
	print(p->link);
}
void main()
    {
     int c=0,ch=0,cho=0,n=0;
     printf("MAIN MENU:");
     printf("\n1 for Enqueue \n2 for Dequeue \n3 for Display");
     do
      {
        printf("Enter choice:");  
        scanf("%d",&cho);
        switch(cho)
              {
                case 1:
                        printf("Enter data:");
                        scanf("%d",&n);
                        printf("Enqueue using \n1>Array\nOR\n2>Linked List");
                        printf("Enter choice:");
                        scanf("%d",&ch);
                        if(ch==1)
                         {
                          EnQueue1(n);
                          }
                        else if(ch==2)
                              {
                                EnQueque2(n);
                              }
                        else
                           {
                             printf("\nWrong Choice!!!")
                           }
                        break;
                case 2:
                        printf("Dequeue using \n1>Array\nOR\n2>Linked List");
                        printf("Enter choice:");
                        scanf("%d",&ch);
                        if(ch==1)
                         {
                          DeQueue1();
                          }
                        else if(ch==2)
                              {
                                DeQueque2(n);
                              }
                        else
                           {
                             printf("\nWrong Choice!!!")
                           }
                        break;
                case 3:
                        printf("Display using \n1>Array\nOR\n2>Linked List");
                        printf("Enter choice:");
                        scanf("%d",&ch);
                        if(ch==1)
                         {
                          Display1();
                          }
                        else if(ch==2)
                              {
                                display2(head);
                              }
                        else
                           {
                             printf("\nWrong Choice!!!")
                           }
                        break;
                default:
                        printf("Incorrect input");
                        break;
              }        
                  
        printf("\nWant to continue?(Y=1,N=2)")
        scanf("%d",&c);
        }while(c==1);
     getch();    
    }