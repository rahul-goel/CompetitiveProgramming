#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pr 0.000001
typedef long long ll;

ll max(ll a, ll b)
{
    return a>b ? a : b;
}
ll min(ll a, ll b)
{
    return a<b ? a : b;
}
int comparetor (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int arr[200005], index[200005];;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &arr[i]);
			index[arr[i]] = i;
		}
		int ans[200005] = {0};
		int mn = 1000000000, mx = -1;
		for(int i=1; i<=n; i++)
		{
			mn = min(index[i], mn);
			mx = max(index[i], mx);

			if(mx-mn+1 == i)
				ans[i] = 1;
		}

		for(int i=1; i<=n; i++)
			printf("%d", ans[i]);
		printf("\n");
	}    

    return 0;
}