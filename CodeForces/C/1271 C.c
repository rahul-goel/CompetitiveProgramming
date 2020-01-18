//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, sx, sy;
	scanf("%d %d %d", &n, &sx, &sy);
	int north_x = sx, north_y = sy+1;
	int east_x = sx+1, east_y = sy;
	int south_x = sx, south_y = sy-1;
	int west_x = sx-1, west_y = sy;

	int c_north=0, c_east=0, c_south=0, c_west=0;
	while(n--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(x>sx)
			c_east++;
		else if(x<sx)
			c_west++;

		if(y>sy)
			c_north++;
		else if(y<sy)
			c_south++;
	}

	int ans = max(max(c_north, c_east), max(c_south, c_west));
	printf("%d\n", ans);
	//printf("%d %d %d %d\n", c_north, c_east, c_south, c_west);
	if(ans == c_north)
		printf("%d %d\n", north_x, north_y);
	else if(ans == c_east)
		printf("%d %d\n", east_x, east_y);
	else if(ans == c_south)
		printf("%d %d\n", south_x, south_y);
	else
		printf("%d %d\n", west_x, west_y);

	return 0;
}