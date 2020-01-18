//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
typedef long long ll;

int main()
{
    ll n;   scanf("%lld", &n);
    ll sq = sqrt(n);
    ll a, b;
    for(ll i=sq; i>=1; i--)
    {
        if(n%i==0)
        {
            a = i;
            b = n/i;
            break;
        }
    }
    printf("%lld\n", a+b-2);
    return 0;
}