#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

int main()
{
	ll a, b, c, d, e, f;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	if(e>f)
	{
		ll ans = e * min(a,d), temp = min(a, d);
		a -= temp, d -= temp;
		ans += f * min(min(b, c), d);
		printf("%lld\n", ans);
	}
	else
	{
		ll ans = f * min(min(b, c), d), temp = min(min(b, c), d);
		b -= temp, c -= temp, d -= temp;
		ans += e * min(a, d);
		printf("%lld\n", ans);

	}
	return 0;
}