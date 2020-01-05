#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int scores[10] = {0};
		int n;
		scanf("%d", &n);
		while(n--)
		{
			int p, s;
			scanf("%d %d", &p, &s);
			scores[p] = max(scores[p], s);
		}
		int ans = 0;
		for(int i=0; i<=8; i++)
			ans += scores[i];
		printf("%d\n", ans);
	}
	return 0;
}