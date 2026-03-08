#include <stdio.h>
void complexity(int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j=j*2)
        {
            count++;
        }
    }
    for(int i=0;i<5*n;i++)
    {
        count++;
    }
    for(int i=0;i<10;i++)
    {
        count++;
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