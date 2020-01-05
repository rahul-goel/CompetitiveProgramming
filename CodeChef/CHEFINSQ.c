#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b);
long long int comb(int a, int b);

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n,k;
        scanf("%d %d", &n, &k);
        int *seq = malloc(sizeof(int)*n);
        for(int i=0; i<n; i++)
            scanf("%d", &seq[i]);
        qsort(seq, n, sizeof(int), cmpfunc);
        int count=0;
        for(int i=1; seq[k+i-1]==seq[k-1]; i++)
            count++;
        int j=k;
        for(int i=k-1; seq[i-1]==seq[k-1]; i--)
        {
            count++;
            j=i;
        }
        long long int ans = comb(count+1,k-j+1);
        printf("%lld\n", ans);
        free(seq);
    }
    return 0;
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

long long int comb(int a, int b)
{
    if((a-b)<b)
        b = a-b;
    long long int value = 1;
    for(int i=1; i<=b; i++)
    {
        value = (long long int)((double)value * (double) a / (double) i);
        a--;
    }
    return value;
}