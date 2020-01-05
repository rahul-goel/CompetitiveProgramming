#include <stdio.h>
#include <stdlib.h>
 
int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, arr[105];
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), comp);
        int count = 0, flag = 0, ptr = 0, prev = -1;
        while(1)
        {
            if(arr[ptr] != -1)
            {
                flag = 1;
                if(arr[ptr]-prev>1)
                    prev = arr[ptr], arr[ptr] = -1;
            }
            
            if(flag == 0 && ptr == n-1)
                break;
 
            if(ptr == n-1)
            {
                count++, prev = -1, flag = 0, ptr=0;
                continue;
            }
            ptr++;
        }
        printf("%d\n", count);
    }
    return 0;
}