#include <stdio.h>
#include <stdlib.h>
typedef struct ArrayStack
{
    int top;
    int capacity;
    int *array;
} Stack_data_type;
Stack_data_type *stack;
void create_stack(int);
int full();
int empty();
void push();
void pop();
void display();
int main()
{
    int length, choice = 0, element;
    printf("Enter the length of the stack.\n");
    scanf("%d", &length);
    create_stack(length);
    while (1)
    {
        printf("Which operation do you want to perform.\n1. Press 1 to PUSH the element.\n2. Press 2 to POP the element.\n3. Press 3 to display the element.\n4. Press 4 to exit.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please! enter valid choice.\n");
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
    stack->array = (int *)malloc(sizeof(int) * stack->capacity);
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
void push()
{
    int data;
    if (!full())
    {
        printf("Enter the element that you want to insert.\n");
        scanf("%d", &data);
        stack->top = stack->top + 1;
        stack->array[stack->top] = data;
    }
    else
        printf("OVERFLOW - Sorry,stack is full.\n");
}
void pop()
{
    int element;
    if (!empty())
    {
        element = stack->array[stack->top];
        stack->top = stack->top - 1;
    }
    else
        printf("UNDERFLOW - Sorry,stack is empaty.\n");
}
void display()
{
      int i;
    if(stack->top>=0){
    for (i = stack->top; i >= 0; i--)
        printf("%d ", stack->array[i]);}
   else 
        printf("Stack is empty");
    printf("\n");
}