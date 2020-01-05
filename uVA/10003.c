/* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=944&mosmsg=Submission+received+with+ID+24231602
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memo[55][55], vis[55][55];

int comp(const void* a, const void* b)
{
	return (*(int *)a - *(int *)b);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int solve(int arr[], int i, int j)
{
	if(i+1 == j)
		return 0;
	if(vis[i][j])
		return memo[i][j];
	vis[i][j]++;

	int returnvalue = 1000000000;

	for(int r=i+1; r<j; r++)
		returnvalue = min(returnvalue, solve(arr, i, r) + solve(arr, r, j));
	return memo[i][j] = returnvalue + arr[j]-arr[i];
}

int main()
{
	while(1)
	{
		memset(memo, 0, sizeof(memo));
		memset(vis, 0, sizeof(vis));

		int l, n;
		scanf("%d", &l);
		if(l==0)
			break;
		scanf("%d", &n);

		int *arr = (int *)malloc(sizeof(int)*(n+2));

		arr[0] = 0, arr[n+1] = l;
		for(int i=1; i<=n; i++)
			scanf("%d", &arr[i]);
		qsort(arr, n+2, sizeof(int), comp);

		printf("The minimum cutting is %d.\n", solve(arr, 0, n+1));

		free(arr);
	}
	return 0;
}
