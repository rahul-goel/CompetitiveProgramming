//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
int main()
{
    long long  r, x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld %lld", &r, &x1, &y1, &x2, &y2);
    long double length = sqrt(pow(x2-x1,2)+pow(y2-y1, 2));
    long long int ans = ceil(length/(2*r));
    printf("%lld\n", ans);
    return 0;
}