/*DEBRUP SARKAR, ROLL NO.=54,CSE
  ASSIGNMENT 7
  Q1> Write a menu driven program in C which will perform the following operations on Circular Linked List.

    i)    create a circular linked list
    ii)   insert a node at the beginning
    iii)  insert a node at the end
    iv)  delete a node at the front
    v)   delete a node at the end
    vi)  delete the circular list
    vii) display the list*/


#include <stdio.h>
#include <stdlib.h>
struct node 
    {
    int data;
    struct node * nextptr;
    }*stnode;
void CLC(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->data = num;
        stnode->nextptr = NULL;
        preptr = stnode;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &num);
            newnode->data = num;
            newnode->nextptr = NULL;	
            preptr->nextptr = newnode;
            preptr = newnode;   		
        }
        preptr->nextptr = stnode; 		
    }
}

void CLB(int num)
{
    struct node *newnode, *curNode;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data= num;
        newnode->nextptr = stnode;
        curNode = stnode;
        while(curNode->nextptr != stnode)
        {
            curNode = curNode->nextptr;
        }
        curNode->nextptr = newnode;
        stnode = newnode;
    }
}
void CLE(int num1)
{
        struct node *p;
		int a;
		a=num1;
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=a;
		p=stnode;
		while(p->nextptr!=stnode)
		{
			p=p->nextptr;
		}
		p->nextptr=temp;
		temp->nextptr=stnode;
}
void CLDB()
{
        struct node*p,*store;    
		p=stnode;
		while(p->nextptr!=stnode)
		{
			p=p->nextptr;
		}
		store=stnode;
		stnode=stnode->nextptr; 
		printf("\n The deleted node is -> %d",store->data);
		p->nextptr=stnode;
		free (store);
}
void CLDE()
{
        struct node *p,*q;
		p=stnode;
		while(p->nextptr!=stnode)
		{
			q=p;
			p=p->nextptr;
		}
		q->nextptr=stnode;
		printf("\n The deleted node is : %d",p->data);
		free(p);
}
void del_list()
{
    if (stnode==NULL)
    {
        printf("\n\nElement cannot be deleted.");
    }
    else
    {
        struct node *ptr = stnode->nextptr;
        struct node *temp =(struct node*)malloc(sizeof(struct node));
        while(ptr->nextptr != stnode)
        {
          
            temp = ptr;
            ptr=ptr->nextptr;
            free(temp);
        }
       
        temp = ptr;
        free(temp);
        free(stnode);
        stnode = NULL;
        return stnode;
    }
}
void displayList()
{
    struct node *current;
    int n = 1;

    if(stnode == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    current = stnode;
    printf("DATA IN THE LIST:\n");

    do {
        printf("Data %d = %d\n", n, current->data);

        current = current->nextptr;
        n++;
    }while(current !=stnode);
}
int main()
    {
     int p,q,r,c,ch;
     printf("MENU:");
     printf("\n1 for creating Circular Linked List\n2 for inserting node at the beginning of the list\n3 for inserting node at the end of the list\n4 for deleting node at the beginning\n5 for deleting node at the end of the list\n6 for deleting the Circular Linked List\n7 for displaying the list");
     do
       {
         printf("Enter choice:");
         scanf("%d",&ch);
         switch(ch)
              {
                case 1:
                       printf("\nEnter no. of nodes=");
                       scanf("%d",&p);
                       CLC(p);
                       break;
                case 2:
                       printf("\nEnter data=");
                       scanf("%d",&q);
                       CLB(q);
                       break;
                case 3:
                       printf("\nEnter data=");
                       scanf("%d",&r);
                       CLE(r);
                       break;
                case 4:
                       CLDB();
                       break;
                case 5:
                       CLDE();
                       break;
                case 6:
                       del_list();
                       break;
                case 7:
                       displayList();
                       break;
                default:
                       printf("Invalid Choice");
                }
        printf("\nWant to continue?(Y=1/N=2)");
        scanf("%d",&c);
       }while(c==1);
     return 0;   
    }
