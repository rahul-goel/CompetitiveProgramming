#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int c, s;
		scanf("%d %d", &c, &s);
		int ans = (s/c + 1)*(s/c + 1)*(s%c) + (s/c)*(s/c)*(c - s%c);
		printf("%d\n", ans);
	}
	return 0;
}