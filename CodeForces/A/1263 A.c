#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
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
		int arr[3];
		for(int i=0; i<3; i++)
			scanf("%d", &arr[i]);
		qsort(arr, 3, sizeof(int), comp);
		int ans = 0;
		int temp = min(arr[2] - arr[1], arr[0]);
		ans += temp;
		arr[0] -= temp;
		arr[2] -= temp;
		ans += arr[0];
		arr[1] -= arr[0]/2, arr[0] -= arr[0]/2, arr[2] -= arr[0];
		ans += min(arr[1], arr[2]);
		printf("%d\n", ans);
	}
	return 0;
}