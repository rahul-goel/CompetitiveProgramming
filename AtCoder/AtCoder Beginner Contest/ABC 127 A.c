//Created by Rahul Goel
#include <stdio.h>
#define pr 0.0000001
int main()
{
    double a; int b;
    scanf("%lf %d", &a, &b);
    if(a-13 >= -pr)
        printf("%d\n", b);
    else if(a-13 < pr && a-5>pr)
        printf("%d\n", b/2);
    else if(a-5 <= pr)
        printf("%d\n", 0);
    return 0;
}