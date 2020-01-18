//Created by Rahul Goel
#include <stdio.h>
int min(int a, int b);
int max(int a, int b);
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        int fav = 0, opp = 0;
        int flag = 0;
        for (int i=0; i<n; i++)
        {
            int fu, a , b;
            scanf("%d %d %d", &fu, &a, &b);
            if(fu==1)
            {
                fav=a; opp=b;
                printf("YES\n"); flag = 0;
                continue;
            }
            else if(a==b)
            {
                printf("YES\n"); flag = 0;
                continue;
            }
            else if(flag==1)
            {
                printf("NO\n"); flag = 1;
                continue;
            }
            else
            {
                if(min(a,b)>=max(fav,opp))
                {
                    printf("NO\n"); flag = 1;
                    continue;
                }
                else
                {
                    printf("YES\n"); flag = 0;
                    if(fav<=opp)
                    {
                        fav = min(a,b); opp = max(a,b);
                    }
                    else
                    {
                        fav = max(a,b); opp = min(a,b);
                    }
                    continue;
                }
            }
        }
    }
    return 0;
}
int min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}