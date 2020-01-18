//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
typedef long long ll;
int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        ll str, intel, exp;
        scanf("%lld %lld %lld", &str, &intel, &exp);
        ll start = 0, end = exp, mid, pos=-1;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(mid+str>intel+exp-mid)
            {
                pos = mid;
                end = mid-1;
            }
            else if(mid+str<=intel+exp-mid)
                start = mid+1;
        }
        if(pos!=-1)
            printf("%lld\n", exp-pos+1);
        else
            printf("0\n");
    }
    return 0;
}