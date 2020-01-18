//Created by Rahul Goel
#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);

	int arr[55] = {0};
	arr[1] = 1, arr[2] = 2, arr[3] = 4;
	for(int i=4; i<55; i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
	return 0;
}