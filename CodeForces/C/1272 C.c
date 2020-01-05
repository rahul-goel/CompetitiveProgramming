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
    ll n, k;
    scanf("%lld %lld", &n, &k);
    char str[200005];
    ll asci[128] = {0};
    scanf("%s", str);
    for(ll i=0; i<k; i++)
    {
        char s[5];
        scanf("%s", s);
        asci[s[0]] = 1;
    }
    ll arr[200005] = {0};
    ll len = strlen(str);
    ll count = 0, flag = 1;
    for(ll i=0; i<len; i++)
    {
        if(asci[str[i]])
        {
            count++;
            flag = 1;
            arr[i] = count*(count+1)/2;
        }
        else
        {
            count = 0, flag = 0;
        }
    }
    ll ans = 0;
    for(ll i=1; i<=n; i++)
    {
        if(arr[i]==0)
            ans += arr[i-1];
    }
    printf("%lld\n", ans);
    // for(ll i=0; i<=n; i++)
    //     printf("%lld ", arr[i]);
    return 0;
}