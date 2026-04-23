#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s1[100], s2[100], temp[100];
    int i, j;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int m = strlen(s1);
    int n = strlen(s2);

    // Ensure longer string is in columns
    if(m > n) {
        strcpy(temp, s1);
        strcpy(s1, s2);
        strcpy(s2, temp);

        m = strlen(s1);
        n = strlen(s2);
    }

    int dp[m+1][n+1];

    // Fill DP table
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Print table
    printf("\nDP Table:\n     ");
    for(j = 0; j < n; j++)
        printf("%3c", s2[j]);

    printf("\n");

    for(i = 0; i <= m; i++) {
        if(i == 0)
            printf("   ");
        else
            printf("%2c ", s1[i-1]);

        for(j = 0; j <= n; j++) {
            printf("%3d", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nLength of LCS = %d\n", dp[m][n]);

    return 0;
}