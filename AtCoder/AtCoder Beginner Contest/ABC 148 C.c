#include <stdio.h>
typedef long long ll;
ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", (a*b)/gcd(a, b));
	return 0;
}