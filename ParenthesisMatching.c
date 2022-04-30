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
void display();
void parenthesisOperation();
int matching(char, char);
char arr[100];
int main()
{
    int length = 0, i, choice;
    while (1)
    {
        printf("\n1. Press 1 to check the equality of parenthesis.\n2. Press 2 to watch the Problematic Parenthesis.\n3. Press 3 to exit.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the equation that you want to cheack:\n");
            scanf("%s", arr);
            // gets(arr);
            length = strlen(arr);
            create_stack(length);
            parenthesisOperation();
            break;
        case 2:
            display();
            break;
        case 3:
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
void display()
{
    char i;
    if (stack->top >= 0)
    {
        printf("\nUnmatched Parenthesis --->  \" ");
        for (i = stack->top; i >= 0; i--)
            printf("%c ", stack->array[i]);
        printf("\"");
    }
    else
        printf("Perfectly Matched.");
    printf("\n");
}
void parenthesisOperation()
{
    int i = 0;
    char top, currentElement = 0;
    while (arr[i] != '\0')
    {

        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
            currentElement = arr[i];
            push(currentElement);
        }
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            currentElement = arr[i];
            if (matching(stack->array[stack->top], currentElement))
                pop();
            else
                push(arr[i]);    
        }
        i++;
    }
    if (empty())
        printf("Equation is balanced.\n");
    else
        printf("Equation is unbalanced.\n");
}
int matching(char top, char currentElement)
{
    if (top == '(' && currentElement == ')')
        return 1;
    else if (top == '[' && currentElement == ']')
        return 1;
    else if (top == '{' && currentElement == '}')
        return 1;
    else
        return 0;
}