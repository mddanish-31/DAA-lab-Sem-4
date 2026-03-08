#include <stdio.h>
void matrixMultiply(int n)
{
    int A[10][10], B[10][10], C[10][10];
    int count = 0;

    printf("Enter Matrix A:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            C[i][j]=0;

            for(int k=0;k<n;k++)
            {
                C[i][j] += A[i][k] * B[k][j];
                count++;
            }
        }
    }

    printf("\nResult Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    printf("Total Operations = %d",count);
}

int main()
{
    int n;

    printf("Enter size of matrix: ");
    scanf("%d",&n);

    matrixMultiply(n);

    return 0;
}