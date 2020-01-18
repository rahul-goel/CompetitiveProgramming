//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int comp(const void* a, const void* b)
{
	return (int)(*(int *)a - *(int *)b);
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[2005];
	for(int i=0; i<2*n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, 2*n, sizeof(int), comp);
	int sum1 = 0, sum2 = 0;
	for(int i=0; i<n; i++)
		sum1 += arr[i];
	for(int i=n; i<2*n; i++)
		sum2 += arr[i];
	if(sum1 == sum2)
		printf("-1");
	else
		for(int i=0; i<2*n; i++)
			printf("%d ", arr[i]);
	printf("\n");
	return 0;
}