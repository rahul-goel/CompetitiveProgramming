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
    return 0;
}