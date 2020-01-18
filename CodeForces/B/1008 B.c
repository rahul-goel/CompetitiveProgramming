//Created by Rahul Goel
#include <stdio.h>
int max(int a, int b);
int min(int a, int b);
int main()
{
    int n;  scanf("%d", &n);
    int h[1000000] = {0};
    for(int i=0; i<n; i++)
    {
        int wi, hi;
        scanf("%d %d", &wi, &hi);
        if(i==0)
            h[i]=max(hi, wi);
        else if(h[i-1]<max(hi, wi))
            h[i]=min(hi, wi);
        else
            h[i]=max(hi, wi);
    }
    for(int i=0; i<n-1; i++)
    {
        if(h[i+1]>h[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}