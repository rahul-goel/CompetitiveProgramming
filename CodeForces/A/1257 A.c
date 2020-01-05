#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, x, a, b;
		scanf("%d %d %d %d", &n, &x, &a, &b);
		if(a==max(a, b))
		{
			int temp = a;
			a = b, b = temp;
		}

		if(x>=a)
			x-=a-1, a=1;
		else
			a-=x, x=0;
		
		if(x>=(n-b))
			x-=(n-b), b=n;
		else
			b+=x, x=0;

		printf("%d\n", b-a);
	}
	return 0;
}