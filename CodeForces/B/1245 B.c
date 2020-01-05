#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pr 0.000001
typedef long long ll;

ll max(ll a, ll b)
{
    return a>b ? a : b;
}
ll min(ll a, ll b)
{
    return a<b ? a : b;
}
int comparetor (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        int a, b, c;    scanf("%d %d %d", &a, &b, &c);
        char str[105];  scanf("%s", str);
        int cr=0, cp=0, cs=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]=='R')
                cr++;
            else if(str[i]=='P')
                cp++;
            else
                cs++;
        }
        int score = 0;
        score += (b>=cr) ? (cr) : b;
        score += (c>=cp) ? (cp) : c;
        score += (a>=cs) ? (cs) : a;
        int flag = 0;
        if(!(n&1) && score >= n/2)
            flag = 1;
        else if (n&1 && score >= (n+1)/2)
            flag = 1;
        else
            flag = 0;
        char ans[105];
        memset(ans, '.', sizeof(ans));
        if(flag)
        {
            printf("YES\n");
            for(int i=0; i<n; i++)
            {
                if(str[i] == 'R')
                {
                    if(b)
                    {
                        ans[i] = 'P'; b--;
                    }
                }
                else if(str[i] == 'P')
                {
                    if(c)
                    {
                        ans[i]='S'; c--;
                    }
                    
                }
                else if(str[i] == 'S')
                {
                    if(a)
                    {
                        ans[i]='R'; a--;
                    }
                }
            }
            for(int i=0; i<n; i++)
            {
                if(ans[i]=='.')
                {
                    if(b)
                    {
                        ans[i] = 'P';
                        b--;
                    }
                    else if(c)
                    {
                        ans[i] = 'S';
                        c--;
                    }
                    else if(a)
                    {
                        ans[i] = 'R';
                        a--;
                    }
                }
            }
            for(int i=0; i<n; i++)
                printf("%c", ans[i]);
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}