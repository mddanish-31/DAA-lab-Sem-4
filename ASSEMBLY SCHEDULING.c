#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n = 5, i;

    int a1[5], a2[5];
    int t1[4], t2[4];
    int e1, e2, x1, x2;

    // Input processing times
    printf("Enter processing time for Line 1 (5 values):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a1[i]);

    printf("Enter processing time for Line 2 (5 values):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a2[i]);

    // Input transfer times (n-1 = 4)
    printf("Enter transfer time from Line 1 to Line 2 (4 values):\n");
    for(i = 0; i < n-1; i++)
        scanf("%d", &t1[i]);

    printf("Enter transfer time from Line 2 to Line 1 (4 values):\n");
    for(i = 0; i < n-1; i++)
        scanf("%d", &t2[i]);

    // Entry & Exit
    printf("Enter entry times (e1 e2): ");
    scanf("%d %d", &e1, &e2);

    printf("Enter exit times (x1 x2): ");
    scanf("%d %d", &x1, &x2);

    int f1[5], f2[5];

    // Base case
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];

    // DP computation
    for(i = 1; i < n; i++) {
        f1[i] = min(f1[i-1] + a1[i],
                    f2[i-1] + t2[i-1] + a1[i]);

        f2[i] = min(f2[i-1] + a2[i],
                    f1[i-1] + t1[i-1] + a2[i]);
    }

    int final_cost = min(f1[n-1] + x1,
                         f2[n-1] + x2);

    printf("\nMinimum Assembly Cost = %d\n", final_cost);

    return 0;
}