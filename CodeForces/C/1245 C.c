//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pr 0.000001

typedef long long ll;
ll m = 1000000007;

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
    char str[100005];
    scanf("%s", str);
    ll fibo[100005] = {0};
    fibo[0] = 1, fibo[1] = 1;
    for(int i=2; i<100005; i++)
        fibo[i] = (fibo[i-1] + fibo[i-2])%m;
    ll ans = 1;
    int flag = 1;
    for(int i=0, len=strlen(str); i<len; i++)
    {
        if(str[i]=='m' || str[i] == 'w')
        {
            flag = -1;
            break;
        }
        if(str[i] == 'n')
        {
            int j=i;
            while(str[j+1]=='n')
                j++;
            ans = (ans*fibo[j-i+1])%m;
            i = j;
        }
        if(str[i] == 'u')
        {
            int j=i;
            while(str[j+1]=='u')
                j++;
            ans = (ans*fibo[j-i+1])%m;
            i = j;
        }
    }
    if(flag==-1)
        printf("0\n");
    else
        printf("%lld\n", ans);
    return 0;
}