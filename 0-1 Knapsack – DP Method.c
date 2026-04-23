#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    if (a < b)
        return b;
    else
        return a;
}

int main() {
    int n, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    // Input profits
    printf("Enter profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    // Input weights
    printf("Enter weights:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    int M; // Capacity of knapsack
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    int m[n + 1][M + 1]; // DP table

    // Fill DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {

            if (i == 0 || j == 0) {
                m[i][j] = 0; // Base condition
            }
            else if (weight[i - 1] <= j) {
                m[i][j] = max(
                    m[i - 1][j], // exclude item
                    profit[i - 1] + m[i - 1][j - weight[i - 1]] // include item
                );
            }
            else {
                m[i][j] = m[i - 1][j]; // cannot include item
            }
        }
    }

    // Print DP Table
    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", m[n][M]);

    return 0;
}