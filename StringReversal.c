#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ArrayStack
{
    int top;
    int capacity;
    char *array;
} Stack_data_type;
Stack_data_type *stack;
void create_stack(int);
int full();
int empty();
void push(char);
char pop();
void stringReversal();
char arr[100];
int main()
{
    int length = 0, i = 0, choice;
    while (1)
    {
        printf("\n1. Press 1 to reverse the string.\n2. Press 2 to exit.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the string that you want to reverse:\n");
            // scanf("%s", arr);
            gets (arr);
            gets (arr);
            length = strlen(arr);
            create_stack(length);
            stringReversal();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Please! Enter valid choice.\n");
            break;
        }
    }
    return 0;
}
void create_stack(int number)
{
    stack = (Stack_data_type *)malloc(sizeof(Stack_data_type));
    stack->top = -1;
    stack->capacity = number;
    stack->array = (char *)malloc(sizeof(char) * stack->capacity);
}
int full()
{
    if (stack->top == stack->capacity - 1)
        return 1;
    else
        return 0;
}
int empty()
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}
void push(char c)
{
    if (!full())
    {
        stack->top = stack->top + 1;
        stack->array[stack->top] = c;
    }
    else
        printf("OVERFLOW - Sorry,stack is full.\n");
}
char pop()
{
    char element;
    if (!empty())
    {
        element = stack->array[stack->top];
        stack->top = stack->top - 1;
        return element;
    }
}
void stringReversal()
{
    int i;
    printf("\nOriginal String:->>>  ");
    puts(arr);
    for (i = 0; arr[i] != '\0'; i++)
    {
        push(arr[i]);
    }
    for (i = 0; !empty(); i++)
    {
        arr[i] = pop();
    }
    printf("\nString after reversal:->>>  ");
    puts(arr);
}