//Created by Rahul Goel
#include <stdio.h>
typedef long long ll;

int main()
{
	ll n;
	scanf("%lld", &n);
	if(n==1)
		printf("9 8\n");
	else
		printf("%lld %lld\n", 3*n, 2*n);
	return 0;
}