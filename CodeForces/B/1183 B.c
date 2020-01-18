//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max(int a, int b);
int min(int a, int b);
int main()
{
    int q;  scanf("%d", &q);
    while(q--)
    {
        int n, k;   scanf("%d %d", &n, &k);
        int arr[200] = {0};
        int mn = 1000000000, mx=-1;   
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            mn=min(mn, arr[i]); mx=max(mx, arr[i]);
        }
        if(mn+k<mx-k)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", mn+k);
        }
        
    }
    return 0;
}
int max(int a, int b)
{
    if(a>=b)    return a;
    else    return b;
}
int min(int a, int b)
{
    if(a<=b)    return a;
    else    return b;
}