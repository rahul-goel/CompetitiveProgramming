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
	return (int)( *(ll*)a - *(ll*)b );
}
int main()
{
    ll t;
    scanf("%lld", &t);
    while(t--)
    {
    	ll n, p, k;
    	scanf("%lld %lld %lld", &n, &p, &k);
    	ll arr[200005];
    	for(ll i=0; i<n; i++)
    		scanf("%lld", &arr[i]);
    	qsort(arr, n, sizeof(ll), comparetor);
    	//case 1, buy fisrt one immediately
    	ll count1 = 0, coins = p;
    	if(arr[0]<=coins)
    	{
    		coins -= arr[0], count1++;
	    	for(ll i=2; i<n; i+=2)
	    	{
	    		if(arr[i]<=coins)
	    			coins-=arr[i], count1+=2;
	    		else
	    			break;
	    	}
	    }
    	//case2, buy 2 at a time
    	ll count2 = 0;
    	coins = p;
    	for(ll i=1; i<n; i+=2)
    	{
    		if(arr[i]<=coins)
    			coins-=arr[i], count2+=2;
    		else
    			break;
    	}
    	printf("%lld\n", max(count1, count2));
    }
    return 0;
}