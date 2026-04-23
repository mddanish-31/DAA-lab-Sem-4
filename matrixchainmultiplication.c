#include <stdio.h>

int main() {

    
    int A[5][7], B[7][9], C[9][12], D[12][15];

    int n = 4;

    
    int p[5] = {5,7,9,12,15};

    int m[5][5] = {0};
    int i,j,k,L,min,r;

   
    for(L=2;L<=n;L++){
        for(i=1;i<=n-L+1;i++){
            j=i+L-1;
            min=9999;

            for(k=i;k<j;k++){
                r = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(r < min)
                    min = r;
            }

            m[i][j] = min;
        }
    }

  
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i>j)
                printf("0\t");
            else
                printf("%d\t",m[i][j]);
        }
        printf("\n");
    }

    // final answer
    printf("\nMinimum multiplication = %d", m[1][n]);

    return 0;
}