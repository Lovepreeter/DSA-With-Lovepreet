#include <stdio.h>
#include <stdlib.h>
typedef struct ArrayStack
{
    int top;
    int capacity;
    int *lowerStack;
    int *uperStack;
} Stack_data_type;
Stack_data_type *stack;
void create_stack(int);
int full();
int empty();
void push(int, int);
int lowerIndexPop();
int uperIndexPop();
void QuickSort(int *, int);
int pivotGiver(int *, int, int, int);
void display(int *, int);
int main()
{
    int length, choice = 0, element, i, array[100];
    while (1)
    {
        printf("\n1. Press 1 to sort the array.\n2. Press 2 to Exit.\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the length of array: ");
            scanf("%d", &length);
            printf("Enter the element in array:\n");
            for (i = 0; i < length; i++)
                scanf("%d", &array[i]);
            create_stack(length);
            printf("Array Before Sorting: ");
            display(array, length);
            QuickSort(array, length);
            printf("\nArray After Sorting: ");
            display(array, length);
            printf("\n");
            break;
        case 2:
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
    stack->lowerStack = (int *)malloc(sizeof(int) * stack->capacity);
    stack->uperStack = (int *)malloc(sizeof(int) * stack->capacity);
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
void push(int lowerIndex, int uperIndex)
{
    if (!full())
    {
        stack->top = stack->top + 1;
        stack->lowerStack[stack->top] = lowerIndex;
        stack->uperStack[stack->top] = uperIndex;
    }
    else
        printf("OVERFLOW - Sorry,stack is full.\n");
}
int lowerIndexPop()
{
    int lowerIndex;
    if (!empty())
    {
        lowerIndex = stack->lowerStack[stack->top];
    }
    return lowerIndex;
}
int uperIndexPop()
{
    int uperIndex;
    if (!empty())
    {
        uperIndex = stack->uperStack[stack->top];
        stack->top = stack->top - 1;
    }
    return uperIndex;
}
void QuickSort(int *array, int length)
{
    int beg, end, pivot;
    // array with one element is already sorted,so we sort array for greater then one element.
    if (length > 1)
    {
        push(0, length - 1);
        while (stack->top != -1)
        {
            // pop the beg and end number of divided array.
            beg = lowerIndexPop();
            end = uperIndexPop();
            // function call
            pivot = pivotGiver(array, length, beg, end);
            // push the beg and end position number of left sub-array into stack.
            if (beg < pivot - 1)
                push(beg, pivot - 1);
            // push the beg and end position number of right sub-array int stack.
            if (end > pivot + 1)
                push(pivot + 1, end);
        }
    }
}
int pivotGiver(int *array, int length, int beg, int end)
{
    int left = beg, right = end, pivot = beg, temp;
    for (int i = 0; pivot != right || pivot != left; i++)
    {
        // right to left
        while (array[pivot] <= array[right] && pivot != right)
            right--;
        // if pivot find their perfect position
        if (pivot == right)
            return pivot;
        // swapping
        if (array[pivot] > array[right])
        {
            temp = array[pivot];
            array[pivot] = array[right];
            array[right] = temp;
            // set the position of pivot
            pivot = right;
        }
        // left to right
        while (array[left] <= array[pivot] && pivot != left)
            left++;
        // if pivot find their perfect position
        if (pivot == left)
            return pivot;
        // swapping
        if (array[pivot] < array[left])
        {
            temp = array[pivot];
            array[pivot] = array[left];
            array[left] = temp;
            // set the position of pivot
            pivot = left;
        }
    }
}
void display(int *array, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d  ", array[i]);
    }
}