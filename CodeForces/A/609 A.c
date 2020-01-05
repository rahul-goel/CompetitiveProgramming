#include <stdio.h>
#include <stdlib.h>
int comparetor (const void * a, const void * b)
{
		return -( *(int*)a - *(int*)b );
}
int main()
{
	int n, m;	scanf("%d %d", &n, &m);
	int *arr = malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), comparetor);
	int sum = 0, count = 0;
	for(int i=0; i<n; i++)
	{
		sum+=arr[i];
		if(sum>=m)
		{
			count = i+1;
			break;
		}
	}
	//printf("%d\n", sum);
	printf("%d\n", count);
	free(arr);
	return 0;
}