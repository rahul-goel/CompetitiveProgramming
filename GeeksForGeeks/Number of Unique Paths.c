#include <stdio.h>
#include <string.h>
int main()
{
    int mat[16][16]={0};
    memset(mat, 0, sizeof(mat));
    for(int i=0; i<16; i++)
    {
        mat[0][i] = 1;
        mat[i][0] = 1;
    }
    for(int i=1; i<16; i++)
    {
        for(int j=1; j<16; j++)
            mat[i][j] = mat[i-1][j]+mat[i][j-1];
    }
    int t;  scanf("%d", &t);
    while(t--)
    {
        int m, n;   scanf("%d %d", &m, &n);
        printf("%d\n", mat[m-1][n-1]);
    }
    return 0;
}