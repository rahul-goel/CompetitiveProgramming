//Created by Rahul Goel
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
   	ll t;
   	scanf("%lld", &t);
   	while(t--)
   	{
   		ll a, b, c, r;
   		scanf("%lld %lld %lld %lld", &a, &b, &c, &r);
   		ll x = c-r, y = c+r;
   		if(a>b)
   		{
   			ll temp = a;
   			a = b, b = temp;
   		}
   		if(x<=a && b<=y)
   		{
   			printf("0\n");
   			continue;
   		}
   		ll ans;
   		if(a<=c && c<=b)
   			ans = max(x-a, 0) + max(b-y, 0);
   		else if(c<a)
   			ans = min(b-a, b-y);
   		else
   			ans = min(x-a, b-a);
   		printf("%lld\n", ans);
   	}
    return 0;
}