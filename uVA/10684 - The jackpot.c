#include <stdio.h>
#include <string.h>
typedef long long ll;

int main()
{
	while(1)
	{
		ll n;
		scanf("%lld", &n);
		if(n==0)
			break;
		ll arr[10005] = {0};
		for(ll i=1; i<=n; i++)
			scanf("%lld", &arr[i]);
		ll temp = 0, max = 0;
		for(ll i=1; i<=n; i++)
		{
			temp += arr[i];
			if(temp>max)
				max = temp;
			else if(temp<0)
				temp = 0;
		}
		if(max>0)
			printf("The maximum winning streak is %lld.\n", max);
		else
			printf("Losing streak.\n");
	}
	return 0;
}