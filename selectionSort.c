#include <stdio.h>
int main()
{
    int array[100], min, length, temp,j, i;
    printf("Enter the length of array.\n");
    scanf("%d", &length);
    printf("Enter the elements in array.\n");
    for (i = 0; i < length; i++)
        scanf("%d", &array[i]);
    printf("\nArray before sorting.\n");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
    // main logic
    for (i = 0; i < length-1; i++)
    {
        min=i;
        for (j = i + 1; j < length; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
    }
    // printing the array
    printf("\nArray after sorting.");
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
}