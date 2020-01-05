#include <stdio.h>
int main()
{
    int n, k;  scanf("%d %d", &n, &k);
    int arr[100005];
    int count = 0, a;
    while(n--)
    {
        scanf("%d", &a);
        if(a>=k)
            count++;
    }
    printf("%d\n", count);
    return 0;
}