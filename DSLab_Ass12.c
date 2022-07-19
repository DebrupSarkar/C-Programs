/*DEBRUP SARKAR,ROLL NUMBER=54,CSE
  ASSIGNMENT 12
  Q1>WRITE A MENU DRIVEN PROGRAM IN C WHICH WILL PERFORM THE FOLLOWINNG OPERATIONS ON CIRCULAR DOUBLY LINKED LIST.
    i>CREATE A  CIRCULAR DOUBLY LINKED LIST 
    ii>DELETE THE FIRST NODE  
    iii>DELETE THE LAST NODE 
    iv>DELETE A NODE AFTER A SPECIFIC NODE
    v>DISPLAY THE LIST BEFORE AND AFTER EACH OPERATION*/
#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insert()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          head -> prev = ptr;  
      ptr -> next = head;  
        }  
   }  
     printf("\nnode inserted\n");  
}  
  
void delBeg()  
{  
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == head)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        temp = head;   
        while(temp -> next != head)  
        {  
            temp = temp -> next;  
        }  
        temp -> next = head -> next;  
        head -> next -> prev = temp;  
        free(head);  
        head = temp -> next;  
    }  
  
}  
void delLast()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else 
    {
     ptr=head;
     while(ptr -> next != head)
          {
           ptr = ptr -> next;
          }
     ptr -> prev -> next = head;
     head -> prev = ptr -> prev;
    free(ptr);
    return head;
    }
 }  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              
} 
void delete_after( )  
{  
    struct node *ptr, *temp;   
    int val;   
    printf("Enter the value");  
    scanf("%d",&val);  
    temp = head;  
    while(temp -> data != val)  
    temp = temp -> next;  
    if(temp -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(temp -> next -> next == NULL)  
    {  
        temp ->next = NULL;  
        printf("\nNode Deleted\n");  
    }  
    else  
    {   
        ptr = temp -> next;  
        temp -> next = ptr -> next;  
        ptr -> next -> prev = temp;  
        free(ptr);  
        printf("\nNode Deleted\n");  
    }     
}  
void main()
    {
     int c,ch,n,i,v;
     printf("MENU:");
     printf("\n1 for creating circular doubly linked list\n2 for deleting the first node\n3 for deleting lst node \n4 for deleting after a specified node\n 5 for display");
     do
      {
       printf("\nEnter choice=");
       scanf("%d",&c);
       switch(c)
             {
              case 1:
                     printf("Enter number of nodes=");
                     scanf("%d",&n);
                     for(i=0;i<n;i++)
                        {
                         insert();
                        }
                     display();    
                     break;
              case 2:
                     delBeg();
                     display();
                     break;
              case 3:
                     delLast();
                     display();
                     break;
              case 4:
                     delete_after();
                     display();
                     break;
              case 5:
                     display();
                     break;
              default:
                     printf("\nWrong choice");
                     break;
             }
        printf("\nWant to continue?(Y=1,N=2)");
        scanf("%d",&ch);
       }while(ch==1);
       getch();
    }
  

