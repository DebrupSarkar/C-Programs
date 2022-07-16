/*DEBRUP SARKAR,ROLL NUMBER=54,CSE
  ASSIGNMENT 4
  Q1>WRITE A PROGRAM IN C TO IMPIEMENT QUICK SORT.*/
#include<stdio.h>
void quicksort(int number[25],int f,int l)
   {
    int i, j, pivot, temp;

    if(f<l)
    {
      pivot=f;
      i=f;
      j=l;

      while(i<j)
      {
         while(number[i]<=number[pivot]&&i<l)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)
         {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,f,j-1);
      quicksort(number,j+1,l);

   }
}

int main()
   {
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d",&count);

    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
       scanf("%d",&number[i]);

    quicksort(number,0,count-1);

    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
       printf(" %d",number[i]);

    return 0;
}
