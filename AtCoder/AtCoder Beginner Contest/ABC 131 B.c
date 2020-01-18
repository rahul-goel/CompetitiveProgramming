//Created by Rahul Goel
#include <stdio.h>
#include <math.h>
int min(int a, int b);
int main()
{
    int n, l; scanf("%d %d", &n, &l);
    int arr[500] ={0};
    for(int i=1; i<=n; i++)
        arr[i] = l+i-1;
    int diff[500] = {0};
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum+=arr[i];
    int mn = 1000;
    int store;
    for(int i=1; i<=n; i++)
    {
        diff[i] = sum-arr[i];
        mn = min(mn, fabs(arr[i]));
        if(mn==fabs(arr[i]))
            store = diff[i];
    }
    printf("%d\n", store);
    return 0;
}

int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}