#include <stdio.h>
#include <string.h>
typedef long long ll;
 
int main()
{
	ll t, m = 1000000007;
	scanf("%lld", &t);
	while(t--)
	{
		ll x;
		char s[505];
		scanf("%lld %s", &x, s);
		ll queue[1000005], pop = 0, push = 0, len = strlen(s), ans = len;
 
		for(ll i=0; i<len; i++)
			queue[i] = s[i] - '0';
		push += len;
 
		while(pop<x && push <= x)
		{
			pop++;
			ll paste = queue[pop-1]-1;//1 time it is already pasted
			ll end = push-1;
			ans = (ans + (paste*(push-pop))%m)%m;
			while(paste--)
			{
				for(ll i=pop; i<=end; i++)
				{
					queue[push++] = queue[i];
					if(push > x)
						break;
				}
			}
 
		}
		while(pop<x)
		{
			pop++;
			ans = (ans + ((queue[pop-1]-1)*(ans-pop))%m)%m;
		}
		ans = (ans+m)%m;
		printf("%lld\n", ans);
	}
	return 0;
}
