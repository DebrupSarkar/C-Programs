/*DEBRUP SARKAR,ROLL NUMBER=54,CSE 
  ASSIGNMENT 11
  Q1>WRITE A MENU DRIVEN PROGRAM IN C WHICH WILL PERFORM THE FOLLOWINNG OPERATIONS ON CIRCULAR DOUBLY LINKED LIST.
    i>CREATE A  CIRCULAR DOUBLY LINKED LIST 
    ii>INSERT A NODE AT THE BEGINNING  
    iii> INSERT A NODE AT THE END 
    iv>DISPLAY THE LIST BEFORE AND AFTER EACH OPERATION*/
#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertBeg()  
{  
   struct node *ptr,*temp;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value=");  
    scanf("%d",&item);  
    ptr->data=item;  
   if(head==NULL)  
   {  
      head = ptr;  
      ptr -> next = head;   
      ptr -> prev = head;   
   }  
   else   
   {  
       temp = head;   
    while(temp -> next != head)  
    {  
        temp = temp -> next;   
    }  
    temp -> next = ptr;  
    ptr -> prev = temp;  
    head -> prev = ptr;  
    ptr -> next = head;  
    head = ptr;  
   }  
   printf("\nNode inserted");  
 }  
}     
 
void insertL()  
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
       printf("\nEnter value=");  
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
     printf("\nnode inserted");  
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
void main()
    {
     int n,c,ch;    
     printf("MENU:");
     printf("\n1 for creating Circular Doubly Linked List \n2 for inserting node at the beginning \n3 for inserting node at the end \n4 for displaying the list");
     do 
       {
         printf("\nEnter choice=");
         scanf("%d",&c);
         switch(c)
         {
            case 1:
                   printf("Enter number of nodes=");
                   scanf("%d",&n);
                   while(n!=0)
                        {
                          insertL();
                          n--;
                        }
                    display();
                    break;
            case 2:
                   insertBeg();
                   display();
                   break;
            case 3:
                   insertL();
                   display();
                   break;
            case 4:
                   display();
                   break;
            default:
                    printf("\nWrong Choice");
                    break;
                   
         }
         printf("\nWant to continue(Y=1/N=2)?");
         scanf("%d",&ch);
       }while(ch==1);
    
      getch();
    }
    
  

