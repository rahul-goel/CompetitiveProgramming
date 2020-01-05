#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = a - 2*b;
    if(ans<0)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}