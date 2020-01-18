//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

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
		int n;
		scanf("%d", &n);
		int arr[200005], index[200005], freq[200005] = {0}, flag = -1;
		memset(index, -1, sizeof(index));
		//printf("%d\n", index[5]);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			freq[arr[i]]++;
			if(freq[arr[i]]>=2)
				flag = 1;
		}
		int len = 1000000000;
		int ptr = 0;
		if(n<2 || flag==-1)
		{
			printf("-1\n");
			continue;
		}
		while(ptr<n)
		{
			if(index[arr[ptr]]>=0)
				len = min(len, ptr - index[arr[ptr]] + 1);
			//printf("len %d\n", len);
			index[arr[ptr]] = ptr;
			ptr++;
		}

		printf("%d\n", len);
	}
	return 0;
}