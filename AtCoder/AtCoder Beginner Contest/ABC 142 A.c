#include <stdio.h>
int main()
{
    int n;  scanf("%d", &n);
    if(n&1)
        printf("%0.10lf\n", (double)(n+1)/(2*n));
    else
        printf("%0.10lf\n", 0.5);
}