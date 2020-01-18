//Created by Rahul Goel
#include <stdio.h>
typedef long long ll;
int main()
{
	ll t;
	scanf("%lld", &t);
	while(t--)
	{
		ll n;
		scanf("%lld", &n);
		ll c0=0, c2=0, temp;
		while(n--)
		{
			scanf("%lld", &temp);
			if(temp==0)
				c0++;
			else if(temp==2)
				c2++;
		}
		ll ans = 0;
		if(c2>=2)
			ans += (c2)*(c2-1)/2;
		if(c0>=2)
			ans += (c0)*(c0-1)/2;
		printf("%lld\n", ans);
	}
	return 0;
}