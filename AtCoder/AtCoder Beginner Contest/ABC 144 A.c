//Created by Rahul Goel
#include <stdio.h>
int main()
{
    int a, b;   scanf("%d %d", &a, &b);
    if(a/10 == 0 && b/10 == 0)
        printf("%d\n", a*b);
    else
        printf("-1\n");
    return 0;
}