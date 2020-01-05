#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = 1^2^3^a^b;
	printf("%d\n", ans);

}