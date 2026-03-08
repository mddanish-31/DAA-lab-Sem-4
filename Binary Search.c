#include <stdio.h>
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid, pass = 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        printf("\nPass %d:\n", pass++);
        printf("Low = %d, High = %d, Mid = %d\n", low, high, mid);
        printf("Element at Mid = %d\n", arr[mid]);
        if(arr[mid] == key)
        {
            printf("Element %d found at index %d\n", key, mid);
            return mid;
        }
        else if(arr[mid] < key)
        {
            printf("%d > %d ? Searching Right Half\n", key, arr[mid]);
            low = mid + 1;
        }
        else
        {
            printf("%d < %d ? Searching Left Half\n", key, arr[mid]);
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[50], n, key, i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    result = binarySearch(arr, n, key);
    if(result == -1)
        printf("\nElement not found\n");
    return 0;
}