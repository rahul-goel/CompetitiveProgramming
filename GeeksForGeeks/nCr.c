#include <stdio.h>
typedef long long ll;
ll m = 1000000007;
ll p = 1000000005;

ll fac[1005];

ll power(ll x, ll y, ll f)
{
	ll ans = 1;
	while(y)
	{
		if(y&1)
			ans = ((ans%f)*(x%f))%f;
		y/=2;
		x = ((x%f)*(x%f))%f;
	}
	return ans;
}

int main()
{
	fac[0] = 1;
	for(int i=1; i<1005; i++)
		fac[i] = (i*fac[i-1])%m;
	int t;	scanf("%d", &t);
	while(t--)
	{
		ll n, r;	scanf("%lld %lld", &n, &r);
		if(n<r)
			printf("0\n");
		else if(n==r)
			printf("1\n");
		else
		{
			ll value = fac[n];
			value = ((value%m) * (power(fac[r], p, m)%m))%m;
			value = ((value%m) * (power(fac[n-r], p, m)%m))%m;
			printf("%lld\n", value);
		}
	}
	return 0;
}