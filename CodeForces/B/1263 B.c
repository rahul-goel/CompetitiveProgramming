//Created by Rahul Goel
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
    	char str[10][5];
    	int n;
    	scanf("%d", &n);
    	for(int i=0; i<n; i++)
    		scanf("%s", str[i]);
    	int ptr = 0, repititionflag = -1, count = 0;
    	while(ptr<n)
    	{
    		int checkflag = 0;
    		int ctr = 0;
    		while(ctr<n)
    		{
    			if(ctr==ptr)
    			{
    				ctr++;
    				continue;
    			}
    			if(strcmp(str[ptr], str[ctr])==0)
    			{
    				checkflag = 1;
    				break;
    			}
    			ctr++;
    		}
    		if(checkflag == 1 && repititionflag == -1)
    		{
    			str[ptr][0] = '0', repititionflag++;
    			continue;
    		}
    		if(checkflag == 1 && repititionflag>-1)
    		{
    			str[ptr][0]++, repititionflag++;
    			continue;
    		}
    		if(repititionflag>-1)
    			ptr++, count++, repititionflag = -1;
			else
				ptr++;
    	}
    	printf("%d\n", count);
    	for(int i=0; i<n; i++)
    		printf("%s\n", str[i]);
    }
    return 0;
}