#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *link; 
}node_data_type;
void create(int);
void insertion_in_begining();
void insertion_in_given_position();
void insertion_in_last();
void deletion_in_begining();
void deletion_of_given_element(); 
void deletion_in_last();
void show();
void search() ;
node_data_type *head;
int main()
{ 
    int nodes,end=1,choose;
    head=NULL;
    while (end!=10)
    {
        printf("\nYOU HAVE NUMBER OF CHOICES - WHAT YOU WANT TO DO?\n");
        printf("1.Type = 1 To create a link list.\n2.Type = 2  To insert in begning.\n3.Type = 3  To insert in random position.\n4.Type = 4  To insert at last.\n5.Type = 5  To delete from begining.\n6.Type = 6  To delete from any position.\n7.Type = 7  To delete from the end.\n8.Type = 8  To show the data.\n9.Type = 9  To find the element.\n10.Type = 10  To exit.\n\n");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1 :
            printf("How many nodes do you want to create?\n");
            scanf("%d",&nodes);
            printf("Enter the element=\n");
            create(nodes);
            show();
            break;
        case 2 :
            insertion_in_begining();
            break;    
        case 3 :
            insertion_in_given_position();
            break;
        case 4 :
            insertion_in_last();
            break;   
        case 5 :
            deletion_in_begining();
            break;  
        case 6 :
            deletion_of_given_element();
            break;  
        case 7 :
            deletion_in_last();
            break;  
        case 8 :
            show();
            break;
        case 9 :
            search();
            break;
        case 10 :
            exit(0);
            break;                         
        default:
            printf("You choose invalid option,please valid option.");
        }
}
    
    return 0;
}
void create(int nodes)
{
    node_data_type *adress_taker;
    head = (node_data_type*)malloc(sizeof(node_data_type));
    head->link=NULL;
    scanf("%d",&(head->data));
    adress_taker = head;
    for(int i=1;i<nodes;i++)
    {
        adress_taker->link=(node_data_type*)malloc(sizeof(node_data_type));
        adress_taker=adress_taker->link;
        scanf("%d",&(adress_taker->data));
        adress_taker->link=NULL;
    }
}
void show()
{  
    node_data_type *temp;
    temp=head;
    printf("START->");
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}
void insertion_in_begining()
{
    node_data_type *ship;
    ship=(node_data_type*)malloc(sizeof(node_data_type));
    printf("Which number do you want to enter in begining.\n");
    scanf("%d",&ship->data);
    ship->link=head;
    head=ship;
    show();
} 
void insertion_in_given_position()
{
    node_data_type *given,*temp;
    int loc;
    given=(node_data_type*)malloc(sizeof(node_data_type));
    printf("Enter the element that you want to add in list.\n");
    scanf("%d",&(given->data));
    printf("Enter the position number ,where you want to insert.\n");
    scanf("%d",&loc);
    temp=head;
    for(int i=1;i<loc-1;i++)
    {
      temp=temp->link;
    }
    given->link=temp->link;
    temp->link=given;

    show();
}
void insertion_in_last()
{
   node_data_type *ship,*temp;
   ship=(node_data_type*)malloc(sizeof(node_data_type));
   printf("Which number do you want to insert in last.\n");
   scanf("%d",&(ship->data));
   temp=head;
   while(temp->link!=NULL){
       temp=temp->link;
   }
   temp->link=ship;
   ship->link=NULL;
   show();
}
void deletion_in_begining()
{
   node_data_type *ship;
   ship=head;
   head=ship->link;
   free(ship);
   show();
}
void deletion_of_given_element()
{
    node_data_type *match,*temp,*temp2;
    int element,position=0,change;
    printf("Enter the element ,which do you want to delete \n");
    scanf("%d",&element);
    match=head;
    while(match != NULL)
    {
        position++;
        if(match->data==element)
        {
            change=0;
            break;
        }
        else
        {
            change =1;
        }
        match =match->link;
    }
    if(change==1)
    {
        printf("Sorrry , This number is not present in list.\n");
    }
    temp=head;
    for(int i=1;i<position;i++)
    { 
        temp2=temp;
      temp=temp->link;
    }
    temp2->link=temp->link;
    free(temp);
    show();
}
void deletion_in_last()
{
    node_data_type *ship ,*temp;
    if(head->link==NULL)
    {
        head=NULL;
        free(head);
        printf("Now node is empty.\n");
    }
    else
    {
        ship=head;
    while(ship->link!=NULL)
    {
        temp=ship;
        ship=ship->link;
    }
    temp->link=NULL;
    free(ship);
    show();
    }
}   
void search()
{
    node_data_type *match;
    int change =0,element , position=0;
    match=head;
    printf("Which element do you want to search ,Please insert!\n");
    scanf("%d",&element);
    while(match != NULL)
    {
        position++;
        if(match->data==element)
        {
            printf("YES , %d is present in %d position in our list.\n",element,position);
            change=0;
            break;
        }
        else
        {
            change =1;
        }
        match =match->link;
    }
    if(change==1)
    {
        printf("Sorrry , This number is not present in list.\n");
    }
}