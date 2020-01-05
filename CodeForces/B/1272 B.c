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
        char str[100005];
        scanf("%s", str);
        int len = strlen(str);
        int u=0, d=0, l=0, r=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]=='U')
                u++;
            else if(str[i]=='D')
                d++;
            else if(str[i]=='L')
                l++;
            else
                r++;
        }
        if(l==0 || r==0)
        {
            if(u>=1 && d>=1)
            {
                printf("2\n");
                printf("UD\n");
            }
            else
            {
                printf("0\n");
            }
            
        }
        else if(u==0 || d==0)
        {
            if(l>=1 && r>=1)
            {
                printf("2\n");
                printf("LR\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            int num1 = (int)(min((ll)l, (ll)r));
            int num2 = (int)(min((ll)u, (ll)d));
            printf("%d\n", num1+num2+num1+num2);
            for(int i=0; i<num1; i++)
                printf("L");
            for(int i=0; i<num2; i++)
                printf("U");
            for(int i=0; i<num1; i++)
                printf("R");
            for(int i=0; i<num2; i++)
                printf("D");
            printf("\n");
        }
        
    }   
    return 0;
}