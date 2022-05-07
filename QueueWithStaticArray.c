#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int capacity;
    int front;
    int rear;
    int *array;
} Queue_data_type;
Queue_data_type *Queue;
void createQueue(int);
int empty();
int full();
void insertion();
void deletion();
void deleteQueue();
void display();
int main()
{
    int lenght, choice;
    printf("Enter the lenght of Queue.\n");
    scanf("%d", &lenght);
    createQueue(lenght);
    while (1)
    {
        printf("\nWhich operation do you want to preform???\n\n1.Press 1 to check the STATUS of Queue.\n2.Press 2 to INSERT an element in Queue.\n3.Press 3 to DELETE an element in Queue.\n4.Press 4 to display the element of Queue.\n5.Press 5 to EXIT.\n\nEnter your choice-\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nCapacity = %d , Front = %d , Rear = %d", Queue->capacity, Queue->front, Queue->rear);
            break;
        case 2:
            insertion();
            break;
        case 3:
            deletion();
            break;
        case 4:
            display();
            break;
        case 5:
            deleteQueue();
            exit(0);
            break;
        default:
            printf("Please!, Enter valid choice.\n");
            break;
        }
    }

    return 0;
}
void createQueue(int length)
{
    Queue = (Queue_data_type *)malloc(sizeof(Queue_data_type));
    Queue->capacity = length;
    Queue->front = -1;
    Queue->rear = -1;
    Queue->array = (int *)malloc(sizeof(int) * Queue->capacity);
}
int empty()
{
    if (Queue->front == -1)
        return 1;
    else
        return 0;
}
int full()
{
    if (Queue->front == 0 && Queue->rear == Queue->capacity - 1)
        return 1;
    else if (Queue->front == Queue->rear + 1)
        return 1;
    else
        return 0;
}

void insertion()
{
    int element;
    printf("Enter the element that you want to insert.\n");
    scanf("%d", &element);
    if (Queue->capacity < 1)
        printf("Insertion not possible.\n");
    else
    {
        if (full())
        {
            printf("Sorry! Insertion is not possible, queue is full.\n");
        }
        else if (empty())
        {
            Queue->rear = Queue->rear + 1;
            Queue->front = Queue->front + 1;
            Queue->array[0] = element;
        }
        else if (Queue->rear == Queue->capacity - 1)
        {
            Queue->rear = 0;
            Queue->array[Queue->rear] = element;
        }
        else
        {
            Queue->rear = Queue->rear + 1;
            Queue->array[Queue->rear] = element;
        }
    }
    display();
    printf("\nCapacity = %d , Front = %d , Rear = %d", Queue->capacity, Queue->front, Queue->rear);
}
void deletion()
{
    int i, element = 0;
    if (empty())
        printf("Sorry deletion is not possible, Queue is empty.\n");
    else if (Queue->front == Queue->rear)
    {
        Queue->front = -1;
        Queue->rear = -1;
    }
    else if (Queue->front == Queue->capacity - 1)
        Queue->front = 0;
    else
        Queue->front = Queue->front + 1;
    display();
    printf("\nCapacity = %d , Front = %d , Rear = %d", Queue->capacity, Queue->front, Queue->rear);
}
void deleteQueue()
{
    free(Queue->array);
    free(Queue);
    Queue = NULL;
}
void display()
{
    int i, j;
    if (empty())
        printf("Queue is empty.\n");
    else if (Queue->front == Queue->rear)
        printf("%d ", Queue->array[0]);
    else if (Queue->front < Queue->rear)
    {
        for (i = Queue->front; i <= Queue->rear; i++)
            printf("%d ", Queue->array[i]);
    }
    else
    {
        for (j = Queue->front; j < Queue->capacity; j++)
            printf("%d ", Queue->array[j]);
        for (j = 0; j <= Queue->rear; j++)
            printf("%d ", Queue->array[j]);
    }
}