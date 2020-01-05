#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        printf("%d\n", 2*x);
    }
    return 0;
}