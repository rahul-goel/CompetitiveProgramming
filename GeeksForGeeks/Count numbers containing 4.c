#include <stdio.h>
#include <math.h>
int main()
{
	int arr[1000005] = {0};
	arr[4] = 1;
	for(int i=5; i<1000005; i++)
	{
		int flag=0, k=i;
		while(k)
		{
			if(k%10==4)
			{
				flag=1;
				break;
			}
			k/=10;
		}
		if(flag==1)
			arr[i] = arr[i-1]+1;
		else
			arr[i] = arr[i-1];
	}
	int t;	scanf("%d", &t);
	while(t--)
	{
		int n;	scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
	return 0;
}