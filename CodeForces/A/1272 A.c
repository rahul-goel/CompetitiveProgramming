//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pr 0.000001
typedef long long ll;

ll max(ll a, ll b)
{
    return a>b ? a : b;
}
ll min(ll a, ll b)
{
    return a<b ? a : b;
}
int comparetor (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a==b && b==c)
            printf("0\n");
        else if(a==b && llabs(b-c)==1)
            printf("0\n");
        else if(a==c && llabs(b-c)==1)
            printf("0\n");
        else if(b==c && llabs(a-c)==1)
            printf("0\n");
        // else if(a==b)
        //     printf("%lld\n", llabs(c-a)-3);
        // else if(a==c)
        //     printf("%lld\n", llabs(c-b)-3);
        // else if(b==c)
        //     printf("%lld\n", llabs(c-a)-3);
        else
        {
            printf("%lld\n", llabs(a-b)+llabs(b-c)+llabs(c-a)-4);
        }
        
    }
    return 0;
}