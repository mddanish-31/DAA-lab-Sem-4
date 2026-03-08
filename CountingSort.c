#include <stdio.h>
void countingSort(int arr[], int n)
{
    int count[100]={0};
    int output[100];
    int max = arr[0];
    int operations = 0;

    for(int i=1;i<n;i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
        operations++;
    }

    for(int i=1;i<=max;i++)
    {
        count[i] += count[i-1];
        operations++;
    }

    for(int i=n-1;i>=0;i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
        operations++;
    }

    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",output[i]);

    printf("\nTotal Operations = %d",operations);
}
int main()
{
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    countingSort(arr,n);
    return 0;
}