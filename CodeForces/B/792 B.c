#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int b = 0, prev = 0;
    int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        arr[i]=i+1;
    while(k--)
    {
        int curr = n-b;
        int s;
        scanf("%d", &s);
        s = (s+prev)%curr;
        prev = s;
        printf("%d ", arr[s]);
        for(int i=s+1; i<curr; i++)
            arr[i-1] = arr[i];
        b++;
    }
    printf("\n");
    free(arr);
    return 0;
}