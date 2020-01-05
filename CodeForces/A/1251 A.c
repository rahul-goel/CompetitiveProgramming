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
    int t;  scanf("%d", &t);
    while(t--)
    {
        char s[505];  scanf("%s", s);
        int asci[256] = {0};
        int len = strlen(s);
        int check = 0;
        int i=0;
        while(i<len)
        {
            int j=i;
            while(s[i]==s[i+1])
                i++;
            if((j-i+1)&1)
                asci[s[i]]++;
            i++;
        }
        for(int k=0; k<256; k++)
        {
            if(asci[k])
                printf("%c", k);
        }
        printf("\n");
    }
    return 0;
}