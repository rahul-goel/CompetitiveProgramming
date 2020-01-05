#include <stdio.h>
#include <stdlib.h>

int binsearch(int search, int arr[], int start, int end)	//for element just greater than or equal to search
{
	int mid, pos=-1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(arr[mid]<search)
			start = mid + 1;
		else
			pos = mid, end = mid - 1;
	}

	return pos;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, m, ta, tb, k;
	scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
	int a[200005], b[200005];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(int i=0; i<m; i++)
		scanf("%d", &b[i]);

	if(k>=n || k>=m)
	{
		printf("-1\n");
		return 0;
	}

	int flag = 1, ans = 0;

	for(int i=0; i<=k; i++)
	{
		int value = binsearch(a[i]+ta, b, 0, m);
		//printf("k %d value %d\n", k, value);
		if(value == -1 || value + k-i >= m)
		{
			flag = -1;
			break;
		}
		ans = max(ans, b[value + k-i ]+tb);
	}
	if(flag == -1)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}