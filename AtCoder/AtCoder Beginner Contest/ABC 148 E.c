//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
typedef long long ll;
//answer looked from editorial
int main()
{
	ll n;
	scanf("%lld", &n);
	if(n&1)
		printf("0\n");
	else
	{
		ll count = 0;
		for(ll i=10; i<=n; i*=5)
			count += n/i;
		printf("%lld\n", count);
	}
	return 0;
}