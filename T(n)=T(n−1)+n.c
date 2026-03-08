#include <stdio.h>
int count = 0;
void func(int n)
{
    if(n == 0)
        return;
    func(n - 1);
    for(int i = 0; i < n; i++)
    {
        count++;
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    func(n);
    printf("Total Operations = %d\n", count);
    return 0;
}