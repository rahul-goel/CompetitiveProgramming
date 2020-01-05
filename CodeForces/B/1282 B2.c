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
	return (int)( *(ll*)a - *(ll*)b );
}
int main()
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
    	ll n, p, k;
    	scanf("%lld %lld %lld", &n, &p, &k);
    	ll arr[200005], prefix[200005];
    	for(ll i=0; i<n; i++)
    		scanf("%lld", &arr[i]);
    	qsort(arr, n, sizeof(ll), comparetor);
    	prefix[0] = arr[0];
    	for(ll i=1; i<n; i++)
    		prefix[i] = prefix[i-1] + arr[i];
    	ll ans = -1, coins = p, count = 0;
    	for(ll i=k-1; i<n; i+=k)
    	{
    		if(arr[i]<=coins)
    			coins -= arr[i], count+=k;
    		else break;
    	}
    	ans = max(ans, count);
    	for(ll j=0; j<k-1; j++)
    	{
    		coins = p;
    		if(prefix[j]<=coins)
    			count = j+1, coins -= prefix[j];
    		else
    			break;

    		for(ll i=j+k; i<n; i+=k)
    		{
    			if(arr[i]<=coins)
    				coins -= arr[i], count += k;
    			else
    				break;
    		}
    		ans = max(count, ans);
    	}

    	printf("%lld\n", ans);
    }
    return 0;
}