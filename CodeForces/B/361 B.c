//Created by Rahul Goel
#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if(n==k)
        printf("-1\n");
    else
    {
        printf("%d ", n-k);
        for(int i=1; i<=n-k-1; i++)
            printf("%d ", i);
        for(int i=n-k+1; i<=n; i++)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}