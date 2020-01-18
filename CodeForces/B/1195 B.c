//Created by Rahul Goel
#include <stdio.h>
long long n, k;
long long func(long long a)
{
    return (a*(a+1)/2) - (n-a);
}
int main()
{
    scanf("%lld %lld", &n, &k);
    long long start=0, end = n, mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if((func(mid) > k))
            end = mid-1;
        else if(func(mid) < k)
            start = mid+1;
        else
            break;
    }
    printf("%lld\n", n-mid);
    return 0;
}