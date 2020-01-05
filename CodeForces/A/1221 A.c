#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int comparetor (const void * a, const void * b);
int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);
        long long int array[101]={0};
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &array[i]);
            array[i] = (double)log2(array[i]);
        }
        qsort(array, n, sizeof(long long int), comparetor);
        int two[30];
        memset(two, 0, sizeof(two));
        for(int i=0; i<n; i++)
            two[array[i]]++;
        for(int i=0; i<11;i++)
        {
            if(two[i]>=2)
            {
                two[i+1]+=(two[i]/2);
                two[i]%=2;
            }
        }
        if(two[11])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

int comparetor (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}