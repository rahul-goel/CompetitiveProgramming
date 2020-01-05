#include <stdlib.h>
#include <stdio.h>
int comparetor (const void * a, const void * b);
int min(int a, int b);
int max(int a, int b);
int main()
{
    int q;  scanf("%d", &q);
    while(q--)
    {
        int n;  scanf("%d", &n);
        int *arr = malloc(4*n*sizeof(int));
        for(int i=0; i<4*n; i++)
            scanf("%d", &arr[i]);
        qsort(arr, 4*n, sizeof(int), comparetor);
        int area = arr[0]*arr[4*n-1];
        int flag = 0;
        for(int i=0; i<2*n; i+=2)
        {
            if(arr[i]!=arr[i+1])
            {
                flag=1; break;
            }
        }
        for(int i=0; i<2*n; i++)
        {
            if(arr[i]*arr[4*n-1-i]!=area)
            {
                flag=1; break;
            }
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
        free(arr);
    }
    return 0;
}
int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int comparetor (const void * a, const void * b)
{
		return ( *(int*)a - *(int*)b );
}