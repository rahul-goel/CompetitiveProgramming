//Created by Rahul Goel
#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        printf("%d\n", 1 + 2*n + n*(n-1)*(n+1)/2);
    }
    return 0;
}