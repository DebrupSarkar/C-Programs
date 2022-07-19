/*DEBRUP SARKAR,ROLL NUMBER=54,CSE
ASSIGNMENT 13
Q1>WRITE A MENU DRIVEN PROGRAM IN C TO IMPLEMENT STACK USING LINKED LIST. THE OPERATIONS ON THE STACK ARE PUSH,POP AND DISPLAY.*/
#include <stdio.h>  
#include <stdlib.h>
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("Not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}  
void main ()  
   {  
    int choice=0;     
    printf("\n    Stack operations using linked list   \n");  
    printf("\nMENU:");
    printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
    do
    {
     printf("\n Enter your choice \n");        
     scanf("%d",&choice);  
     switch(choice)  
           {  
             case 1:  
                   {   
                    push();
                   
                    break;  
                    }  
             case 2:  
                   {  
                    pop();
                    
                    break;  
                   }  
             case 3:  
                   {  
                    display();  
                    break;  
                    }  
             case 4:   
                   {  
                    printf("EXIT");  
                    break;   
                    }  
             default:  
                    printf("Please Enter valid choice ");  
            }  
       }while(choice!=4);  
    getch();
   }  
