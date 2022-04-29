#include<stdio.h>
#include<stdlib.h>
void display(int[]);
void indexinsertion(int[],int);
void indexdeletion(int[]);  
void linearsearch(int[]); 
void binarysearch(int[]); 
int bubblesort(int[]); 
int search(int[],int);
int size;
int main()
{
    int array[100],i,element,index,capacity=100,checker=0,choice;
    printf("Do you want to make an array,if yes,then enter the size of the array.\n");
    scanf("%d",&size);
    printf("Enter the element in your array.\n");
    for(i=0;i<size;i++)
    scanf("%d",&array[i]);
    display(array);
    printf("congratulation,you make your custom array.\n");
    while (checker!=6)
    {
         printf("Which operation do you want to perform on array.\n1. Press 1 to insert an element in array.\n2. Press 2 to delete an element in array.\n3. Press 3 to search an element by linear search method.\n4. Press 4 to search an element by binary search method.\n5. Press 5 to sort array.\n6. Press 6 to display the elements.\n7. Press 7 to EXIT.\n");
         scanf("%d",&choice);
         switch (choice)
         {
         case 1:
               indexinsertion(array,capacity);
             break;
         case 2:
               indexdeletion(array); 
             break;
         case 3:
               linearsearch(array);
             break;
         case 4:
               binarysearch(array); 
             break;
         case 5:
               bubblesort(array);
               display(array);
             break;
         case 6:
               display(array);
             break;    
         case 7:
               exit(0);
             break;
         default:
               printf("Your choice is invalid.Please ! Enter valid choice.\n");
             break;
         }
    }
    
   
    return 0;
}   
void display(int array[])
{
    int i;
    for(i=0;i<size;i++)
    printf("%d ",array[i]);
    printf("\n");
}
void indexinsertion(int array[], int capacity)
{ 
    int element1,index=0,i,element;
     printf("Enter the Eelement which before you want to insert-\n");
    scanf("%d",&element1);
    index=search(array,element1);
    printf("Enter the element do you want to insert.\n");
    scanf("%d",&element);
    if(size>=capacity)
    {
        printf("Sorry,Insertion is not possible,array is full.");
    }
    else
    {
       // index--;
        for(i=size-1;i>=index;i--)
        array[i+1]=array[i];
        array[index]=element;
    }
    size++;
    printf("Array after insertion=\n");
    display(array);
    printf("\n");
}
void indexdeletion(int array[])
{ 
    int index,i,element1;
    printf("Enter the element that you want to delete.\n");
    scanf("%d",&element1);
    index=search(array,element1);
    for(i=index;i<size;i++)
        array[i]=array[i+1];
    size--;
    printf("Array after deletion=\n");
    display(array);
    printf("\n");
}
void linearsearch(int array[])
{  
    int i,element,change=0;
    printf("Enter the element that you want to search.\n");
    scanf("%d",&element);
    for(i=0;i<size;i++)
    {
    if(array[i]==element)
    {
       printf("Yes, %d is present in %d position.\n",element,i+1);
       change=0;
       break;
    }   
    else
       change=1;  
    }
    if(change==1)
       printf("Sorry, %d is not found.\n",element);
}
void binarysearch(int array[])
{
    int low=0,uper=size,middle,element,change=0;
    printf("Enter the element that you want to search\n");
    scanf("%d",&element);
    bubblesort(array);
    while (low<=uper)
    {
      middle=(low+uper)/2;
      if(element==array[middle])
      {
           printf("Yes, %d is present.\n",element);
           return;
      }    
      else if(element>array[middle])   
           low=middle+1;
      else
           uper=middle-1;       
    }
    printf("Sorry, %d is not found.\n",element);
    
}
int bubblesort(int array[])
{
    int i,j,temp=0,session,change;
    session=size;
    for(i=1;i<=session;i++)
    { 
        change=0;
        for(j=0;j<session-i;j++)
        {
          if(array[j]>array[j+1])
          {
              temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
              change=1;
          }
        }
        if(change==0)
            return 0;
    }
    return 0;
}
int search(int array[],int element)
{
    int i,index=0;
    for(i=0;i<=size;i++)
    {
    if(array[i]==element)
        index=i;
    } 
    return index ;   
}