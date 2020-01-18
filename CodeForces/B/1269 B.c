//Created by Rahul Goel
/*Editorial - 
There exists some i, such that (ai+x)modm=b1. Let's enumerate it, then x is (b1−ai)modm.
Like that you can get O(n) candidates, each of them can be checked in O(nlogn) with sort 
or in O(n) if you will note that the order is just cyclically shifting.

therefore check b1-ai;
*/

#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
int comp(const void* a, const void* b)
{
	return (int)(*(ll *)a - *(ll *)b);
}

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

int main()
{
	ll n, m, a[2005], b[2005], ans = 1000000005;
	scanf("%lld %lld", &n, &m);
	for(ll i=0; i<n; i++)
		scanf("%lld", &a[i]);
	for(ll i=0; i<n; i++)
		scanf("%lld", &b[i]);
	qsort(a, n, sizeof(ll), comp);
	qsort(b, n, sizeof(ll), comp);

	for(ll i=0; i<n; i++)
	{
		while(a[i]==a[i+1] && i<n)
			i++;
		ll diff = (b[0]-a[i]+m)%m;
		//printf("diff = %lld\n", diff);
		ll temp[2005];
		for(ll j=0; j<n; j++)
			temp[j] = (a[j]+diff)%m;
		qsort(temp, n, sizeof(ll), comp);
		ll check_flag = 1;
		for(ll j=0; j<n; j++)
		{
			if(b[j]!=temp[j])
			{
				//printf("%lld not equal\n", diff);
				check_flag = 0;
				break;
			}
		}
		if(check_flag)
			ans = min(ans, diff);
	}
	printf("%lld\n", ans);
	return 0;
}