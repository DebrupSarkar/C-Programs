/*DEBRUP SARKAR, ROLL NO.=54,CSE 
  ASSIGNMENT 9
  Q1> Write a menu driven program in C which will perform the following operations on Doubly Linked List.

    i)     create a doubly linked list
    ii)    insert a node at the beginning
    iii)   insert a node at the end
    iv)   display the list before and after the each operation*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*stnode, *ennode;
void DlLC(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));
 
        if(stnode != NULL)
        {
            printf(" Input data for node 1 : "); 
            scanf("%d", &num);
 
            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;    
                    fnNode->nextptr = NULL;
 
                    ennode->nextptr = fnNode;   
                    ennode = fnNode;            
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}
void DLIB(int num)
{
    struct node * newnode;
    if(stnode == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;  // next address of new node is linking with starting node
        newnode->preptr = NULL;     // set previous address field of new node is NULL
        stnode->preptr = newnode;   // previous address of starting node is linking with new node
        stnode = newnode;           // set the new node as starting node
    }
}
void DLIE(int num)
{
    struct node * newnode;
 
    if(ennode == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = NULL;       
        newnode->preptr = ennode;      
        ennode->nextptr = newnode;      
        ennode = newnode;               
    }
}
void display()
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        printf("\n\n Data present in the list are :\n");
 
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; 
        }
    }
}
void main()
    {
        int n,ch,c,x;
        stnode=NULL;
        ennode=NULL;
        printf("MENU:");
        printf("\n1 for creating Doubly linked List\n2 for inserting node at the beginning\n3 for inserting node at the end\n4 for displaying the list");
        do 
          {
            printf("\nEnter choice=");
            scanf("%d",&ch);
            switch(ch)
                  {
                    case 1:
                            printf("Enter no. of nodes=");
                            scanf("%d",&n);
                            DlLC(n);
                            printf("\nDisplay:");
                            display();
                            break;
                    case 2:
                            printf("Enter data=");
                            scanf("%d",&x);
                            printf("\nBEFORE:");
                            display();
                            DLIB(x);
                            printf("\nAFTER:");
                            display();
                            break;
                    case 3:
                            printf("Enter data=");
                            scanf("%d",&x);
                            printf("\nBEFORE:");
                            display();
                            DLIE(x);
                            printf("\nAFTER:");
                            display();
                            break;
                    case 4:
                           printf("\nDoubly linked List:");
                           display();
                           break;
                    default:
                            break;
                            
                  }
            printf("\nWant to continue:(Y=1/N=2)");
            scanf("%d",&c);
          }while(c==1);
        getch();  
    }
