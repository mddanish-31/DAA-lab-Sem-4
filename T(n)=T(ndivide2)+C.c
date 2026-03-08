#include <stdio.h>
int count = 0;
void func3(int n)
{
    if(n <= 1)
        return;

    func3(n/2);

    count++;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    func3(n);
    printf("Total Operations = %d",count);

    return 0;
}