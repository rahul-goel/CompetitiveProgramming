#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int mat[65][65] = {0}, r, c, countA=0;
		scanf("%d %d", &r, &c);
		char dummy;
		scanf("%c", &dummy);
		int row[65]={0}, col[65]={0};
		for(int i=1; i<=r; i++)
		{
			char temp;
			for(int j=1; j<=c; j++)
			{
				scanf("%c", &temp);
				if(temp == 'A')
				{
					mat[i][j] = 1, countA++;
					row[i]++, col[j]++;
				}
				else
					mat[i][j] = 0;
			}
		scanf("%c", &dummy);
		}

		//condition for n possible moves
		if(countA == 0)
		{
			printf("MORTAL\n");
			continue;
		}
		// condition for 0 moves
		if(countA == r*c)
		{
			printf("0\n");
			continue;
		}

		//condition for 1 move
		if(row[1]==c || row[r]==c || col[1]==r || col[c]==r)
		{
			printf("1\n");
			continue;
		}

		//condition for 2 moves, if any row/col exists other than end ones
		//or if any corner is A
		//so that in one move we go to the condition of 1 move
		int row_flag = 0, col_flag = 0;
		for(int i=1; i<=r; i++)
			if(row[i]==c)
				row_flag = 1;
		for(int j=1; j<=c; j++)
			if(col[j]==r)
				col_flag = 1;
		if(row_flag || col_flag || mat[1][1] || mat[1][c] || mat[r][1] || mat[r][c])
		{
			printf("2\n");
			continue;
		}

		//an edge block must be A so that in one move we reach a corner i.e. in one move we reach the case of 2 moves
		int edge_check = 0; //we will use ORing
		for(int i=1; i<=r; i++)
		{
			edge_check = edge_check || mat[i][1];
			edge_check = edge_check || mat[i][c];			
		}
		for(int j=1; j<=c; j++)
		{
			edge_check = edge_check || mat[1][j];
			edge_check = edge_check || mat[r][j];
		}
		if(edge_check)
		{
			printf("3\n");
			continue;
		}

		//now if none of the others satisfy, it has to be done in 4 moves
		printf("4\n");

	}
	return 0;
}