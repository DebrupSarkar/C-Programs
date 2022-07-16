/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    new_node->data  = new_data; 
   
    new_node->next = (*head_ref); 
   
    (*head_ref)    = new_node; 
}
void insertl(struct Node* prev_node, int new_data)  
{  
    if (prev_node == NULL)  
    {  
    printf("the given previous node cannot be NULL");      
    return;  
    }  
        
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;  
  
    new_node->next = prev_node->next;  
  
    prev_node->next = new_node;  
}
void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  
   
    new_node->data  = new_data; 
  
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
}
void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
} 
int getCount(struct Node* head) 
{ 
    int count = 0;   
    struct Node* current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 
  
int main() 
{ 
  struct Node* head = NULL; 
  char c;
  int p,q,r;
  int d;
  do
    {
     printf("MENU:\nA for Adding node at the end of the list\nB for counting no.of nodes in the list\nC for adding a new node at the beginning of the list\nD for adding a new node after the specified no. of nodes\nE for displaying the contents of the list");
     printf("\nEnter choice:");    
     scanf("%c",&c);
     switch(c)
           {
             case 'A': 
                      printf("\nEnter data=");
                      scanf("%d",&p);
                      append(&head, p);
                      break;
             case 'B':
                      getCount(&head);
                      break;
             case 'C':
                      printf("\nEnter data=");
                      scanf("%d",&q);
                      push(&head,q);
                      break;
             case 'D':
                      printf("Enter data=");
                      scanf("%d",&r);
                      insertl(head->next,r);
                      break;
             case 'E':  
                      printf("\n Created Linked list is: ");
                      printList(head); 
                      break;
             default:
                     printf("\nInvalid Choice.");
           }         
             
      printf("\nWant to continue?(Y=1/N=2):");
      scanf("%d",&d);
    }while(d==1);
  printf("\nEND");
  
  return 0; 
} 
