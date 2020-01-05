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

    int t;
    scanf("%d", &t);
    while(t--)
    {
        char s[100005];
        scanf("%s", s);
        int len = strlen(s);
        int flag = 1;
        for(int i=0; i<len-1; i++)
        {
            if(s[i]==s[i+1] && s[i]!='?')
                flag = -1;
        }
        if(flag == -1)
        {
            printf("-1\n");
            continue;
        }

        if(s[0] == '?')
        {
            if(s[1] == 'a')
                s[0] = 'b';
            else if(s[1] == 'b')
                s[0] = 'c';
            else
                s[0] = 'a';
        }
        int i = 1;
        while(i<len)
        {
            if(s[i] == '?')
            {
                if(s[i-1] == 'a')
                {
                    if(s[i+1] == 'b')
                        s[i] = 'c';
                    else if(s[i+1] == 'c')
                        s[i] = 'b';
                    else
                        s[i] = 'b';
                } 

                if(s[i-1] == 'b')
                {
                    if(s[i+1] == 'a')
                        s[i] = 'c';
                    else if(s[i+1] == 'c')
                        s[i] = 'a';
                    else
                        s[i] = 'a';

                } 

                if(s[i-1] == 'c')
                {
                    if(s[i+1] == 'b')
                        s[i] = 'a';
                    else if(s[i+1] == 'c')
                        s[i] = 'b';
                    else
                        s[i] = 'b';
                }
            }
            i++; 
        }

        printf("%s\n", s);
    }

    return 0;
}