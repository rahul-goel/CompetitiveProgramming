//Created by Rahul Goel
#include <stdio.h>
/*
solve equation. sum of no. on dice = 21. let k+1 dices.
21(k+1) - 7k - t = x ; sum of opp sides of dices = 7; t = top dice bottom number;
14k + 21 - t = x; now 21 - t is also kind of t only (a number on the dice)
so x = 14k + t; where 1<=t<=6;
*/
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%lld", &n);
		if(n<=14)
		{
			printf("NO\n");
			continue;
		}
		if(n%14 >= 1 && n%14 <=6)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}