#include <stdio.h>
int max(int a, int b);
int main()
{
    int n;
    scanf("%d", &n);
    int arr[200] = {0};
    int count=0, sum=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]==1)
            count++;
        sum+=arr[i];
    }
    if(sum==n)
    {
        printf("%d\n", n-1);
        return 0;
    }
    int diff[10000] = {0};
    int k = 0;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==0)
        {
            int count0=0, count1=0;
            for(int j=i; j<=n; j++)
            {
                if(arr[j]==0)
                    count0++;
                else
                    count1++;
                diff[k] = count0-count1;
                k++;
            }
        }
    }
    int mx=0;
    for(int i=0; i<10000; i++)
        mx = max(mx, diff[i]);
    printf("%d\n", count+mx);
    return 0;
}
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}