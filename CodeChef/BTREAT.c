//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
ll min(ll a, ll b)
{
	return a<b ? a : b;
}
ll max(ll a, ll b)
{
	return a>b ? a : b;
}
int main()
{
	ll t;	
	scanf("%lld", &t);
	while(t--)
	{
		ll n;
		scanf("%lld", &n);
		ll arr[1000005];
		for(ll i=0; i<n; i++)
			scanf("%lld", &arr[i]);
		ll sum = 0, mn = 1000000000, mx = -1;
		for(ll i=0; i<n; i++)
		{
			sum += arr[i];
			mn = min(mn, arr[i]);
			mx = max(mx, arr[i]);
		}
		if(sum%n)
			printf("No Treat\n");
		else
		{
			ll mid = sum/n;
			ll count = 0;
			for(ll i=0; i<n; i++)
			{
				if(arr[i]>mid)
					count += arr[i]-mid;
			}
			printf("%lld\n", count);
		}
	}
	return 0;
}