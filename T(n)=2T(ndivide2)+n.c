#include <stdio.h>
int count = 0;
void func1(int n)
{
    if(n <= 1)
        return;

    func1(n/2);
    func1(n/2);

    for(int i = 0; i < n; i++)
    {
        count++;
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    func1(n);
    printf("Total Operations = %d",count);
    return 0;
}