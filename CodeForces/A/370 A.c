//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
int min(int a, int b)
{
    return a<b ? a : b;
}
int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(x1==x2 && y1==y2)
    {
        printf("0 0 0\n");
        return 0;
    }
    //rook
    if(x2 == x1 || y2 == y1)
        printf("1 ");
    else
        printf("2 ");
    //bishop
    if(((x1+y1) & 1) != ((x2+y2) & 1))
        printf("0 ");
    else if((int)fabs(x2-x1) == (int)fabs(y2-y1))
        printf("1 ");
    else
        printf("2 ");
    //king
    if((int)fabs(x2-x1) == min(fabs(x1-x2), fabs(y1-y2)))
        printf("%d\n", (int)fabs(y2-y1));
    else
        printf("%d\n", (int)fabs(x2-x1));
    return 0;
}