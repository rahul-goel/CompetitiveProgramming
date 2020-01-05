#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int count = 0, k = 1;
	while(n--)
	{
		int m;
		scanf("%d", &m);
		if(m != k)
			count++;
		else
			k++;
	}
	if(k==1)
		printf("-1\n");
	else
		printf("%d\n", count);
	return 0;
}