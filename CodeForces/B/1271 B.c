//Created by Rahul Goel
#include <stdio.h>

int main()
{
	int n, arr[205];
	scanf("%d", &n);
	char str[205];
	scanf("%s", str);
	for(int i=0; i<n; i++)
	{
		if(str[i]=='B')
			arr[i+1] = 0;
		else
			arr[i+1] = 1;
	}
	int countmove = 0, ans[1000], k=0;
	for(int i=1; i<=n-1; i++)
	{
		if(arr[i]==0)
			countmove++, ans[k++]=i, arr[i]=1, arr[i+1] = (arr[i+1]==0 ? 1 : 0);
	}
	if(arr[n] == 0)
	{
		for(int i=1; i<=n-1; i++)
		{
			if(arr[i])
				countmove++, ans[k++]=i, arr[i]=0, arr[i+1] = (arr[i+1]==0 ? 1 : 0);
		}
		if(arr[n])
		{
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", countmove);
	for(int i=0; i<k; i++)
		printf("%d ", ans[i]);
	printf("\n");

	// for(int i=1; i<=n; i++)
	// 	printf("%d", arr[i]);
	// printf("\n");
	return 0;
}