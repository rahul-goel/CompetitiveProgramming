//Created by Rahul Goel
#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

int main()
{
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	ll ans;
	if(a == b)
		ans = a*2 + c*2;
	else
		ans = min(a, b)*2 + 1 + c*2;
	printf("%lld\n", ans);
	return 0;
}