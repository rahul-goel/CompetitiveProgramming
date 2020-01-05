/*
method seen from editorial. black and white method
assuming bottommost cell of the first column to be white.
*/

#include <stdio.h>

long long min(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[300005];
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	long long countblack = 0, countwhite = 0;
	for(int i=1; i<=n; i++)
	{
		if(i&1)
			countblack += arr[i]/2, countwhite += (arr[i]&1 ? arr[i]/2 + 1 : arr[i]/2);
		else
			countblack += (arr[i]&1 ? arr[i]/2 + 1 : arr[i]/2), countwhite += arr[i]/2;
	}
	printf("%lld\n", min(countwhite, countblack));
	return 0;
}