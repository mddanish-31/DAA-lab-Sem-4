#include <stdio.h>
void complexity(int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                count++;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            count++;
        }
    }
    for(int i=0;i<7;i++)
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