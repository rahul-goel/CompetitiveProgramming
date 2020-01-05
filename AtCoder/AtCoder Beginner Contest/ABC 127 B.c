#include <stdio.h>
long long algae(long long year);
long long d, r;
long long arr[20];
long long main()
{
    for(long long i=0; i<20; i++)
        arr[i] = -1;
    scanf("%lld %lld %lld", &r, &d, &arr[0]);
    for(long long i=1; i<=10; i++)
        printf("%lld\n", algae(i));
    return 0;
}

long long algae(long long year)
{
    if(arr[year]!=-1)
        return arr[year];
    else
        return (arr[year] = algae(year-1)*r - d);
}