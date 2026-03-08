#include <stdio.h>
void modifiedBubbleSort(int arr[], int n)
{
    int i, j, temp, swapped;
    for(i = 0; i < n-1; i++)
    {
        swapped = 0; 
        printf("\nPass %d:\n", i+1);
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;   // swap happened
            }
        }
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
        if(swapped == 0)
        {
            printf("Array already sorted. Stopping early.\n");
            break;
        }
    }
}
int main()
{
    int arr[50], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    modifiedBubbleSort(arr, n);
    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}