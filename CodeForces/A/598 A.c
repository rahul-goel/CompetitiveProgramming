//Created by Rahul Goel
#include <stdio.h>
typedef long long ll;
int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        ll n;   scanf("%lld", &n);
        ll ans = n*(n+1)/2;
        ll value = 0;
        ll power = 1;
        while(power<=n)
        {
            value += power;
            power = power<<1;
        }
        ans = ans-2*value;
        printf("%lld\n", ans);
    }
    return 0;
}