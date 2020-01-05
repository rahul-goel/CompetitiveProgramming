#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
//USING THE IDEA OF SIEVE OF ERASTHANOSES
int main()
{
	ll n;
	scanf("%lld", &n);
	ll arr[100005];
	memset(arr, -1, sizeof(arr));
	ll colour = 0;
	for(ll i=2; i<=n; i++)
	{
		if(arr[i] == -1)
		{
			colour ++, arr[i] = colour;
			for(ll j=i*i; j<=n; j+=i)
				arr[j] = colour;
		}
	}

	for(ll i=2; i<=n; i++)
		printf("%lld ", arr[i]);
	printf("\n");
	return 0;
}