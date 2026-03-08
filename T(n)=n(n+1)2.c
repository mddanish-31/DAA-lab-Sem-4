#include <stdio.h>
void complexity(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            count++;
        }
    }
    printf("Total Operation Executed : %d",count);
}
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    complexity(n);
    return 0;
}