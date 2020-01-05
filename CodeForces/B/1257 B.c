#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(x==1 && y>1)
			printf("NO\n");
		else if(x==2 && y>3)
			printf("NO\n");
		else if(x==3 && y>3)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}