//Created by Rahul Goel
#include <stdio.h>

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int r, c;
	int k = 1;
	scanf("%d %d", &r, &c);
	if(r==1 && c==1)
	{
		printf("0\n");
		return 0;
	}
	if(r==1)
	{
		for(int i=1; i<=c; i++)
			printf("%d ", i+1);
		printf("\n");
		return 0;
	}
	else if(c==1)
	{
		for(int i=1; i<=r; i++)
			printf("%d\n", i+1);
		return 0;
	}
	int mat[505][505];
	for(int i=1; i<=r; i++)
		mat[i][0] = k++;
	for(int j=1; j<=c; j++)
		mat[0][j] = k++;
	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=c; j++)
			mat[i][j] = (mat[0][j]*mat[i][0])/(gcd(mat[0][j], mat[i][0]));
	}
	
	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=c; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return 0;
}