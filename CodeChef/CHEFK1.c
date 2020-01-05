#include <stdio.h>
#include <math.h>
long long int comb(long long int a, long long int b);
int main(void)
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,m;
        scanf("%lld %lld", &n, &m);
        if(n==1)
        {
            if(m==0)
                printf("%d\n", 0);
            if(m==1)
                printf("%d\n", 1);
            if(m>=2)
                printf("%d\n", -1);
        }    
        else if(n==2)
        {
            if(m==1)
                printf("%d\n", 1);
            else if(m==2 || m==3)
                printf("%d\n", 2);
            else
                printf("%d\n", -1);
        }
        else if((m<n-1) || m>(comb(n,2)+n))
            printf("%d\n", -1);
        else if(m>=n-1 && m<=n+1)
            printf("%d\n",2);
        else if(m>n+1 && m<=2*n)
            printf("%d\n", 3);
        else
        {
            long long int j = m-2*n;
            long long int ans = ceil((double)(j*2)/n) + 3;
            printf("%lld\n", ans);
        }        
    }

    return 0;
}

long long int comb(long long int a, long long int b)
{
    if((a-b)<b)
        b = a-b;
    long long int value  = 1;
    for(long long int i=1; i<=b; i++)
    {
        value = (long long int)((double)value * (double) a / (double) i);
        a--;
    } 
    return value;
}