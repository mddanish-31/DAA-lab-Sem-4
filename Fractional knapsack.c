#include <stdio.h>

int n;
float weight[20], profit[20], ratio[20];
float capacity, totalProfit = 0;

void knapsack(int i) {
    if (i >= n || capacity <= 0)
        return;

    if (weight[i] <= capacity) {
        printf("Take full item %d\n", i + 1);

        totalProfit += profit[i];
        capacity -= weight[i];

        printf("Profit added = %f\n", profit[i]);
        printf("Total Profit = %f\n", totalProfit);
        printf("Remaining weight = %f\n\n", capacity);

        knapsack(i + 1);
    } else {
        float fraction = capacity / weight[i];

        printf("Take fraction of item %d\n", i + 1);

        totalProfit += profit[i] * fraction;

        printf("Profit added = %f\n", profit[i] * fraction);
        printf("Total Profit = %f\n", totalProfit);

        capacity = 0;
    }
}

int main() {
    int i, j;
    float temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &weight[i]);
    }

    printf("Enter profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &profit[i]);
    }

    printf("Enter maximum capacity: ");
    scanf("%f", &capacity);

    // Calculate ratio
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {

                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("\nSteps:\n\n");
    knapsack(0);

    printf("\nFinal Total Profit = %f\n", totalProfit);

    return 0;
}