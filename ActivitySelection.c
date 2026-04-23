#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }

    printf("Enter finish times:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &finish[i]);
    }

    printf("\nSelected Activities:\n");

    i = 0;
    printf("A%d ", i + 1);

    for(j = 1; j < n; j++)
    {
        if(start[j] >= finish[i])
        {
            printf("A%d ", j + 1);
            i = j;
        }
    }

    return 0;
}