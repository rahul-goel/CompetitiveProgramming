//Created by Rahul Goel
#include <stdio.h>
typedef long long ll;
int main()
{
    ll n, m;    scanf("%lld %lld", &n, &m);
    ll rooms[200005]={0};
    for(ll i=2; i<=n+1; i++)
        scanf("%lld", &rooms[i]);
    for(ll i=2; i<=n; i++)
        rooms[i]+=rooms[i-1];
    while(m--)
    {
        ll num; scanf("%lld", &num);
        ll start=1, end=n, mid, pos=-1;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(rooms[mid]<num)
            {
                pos=mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        printf("%lld %lld\n", pos, num-rooms[pos]);
    }
    return 0;
}