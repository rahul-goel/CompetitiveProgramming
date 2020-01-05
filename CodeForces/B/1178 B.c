#include <string.h>
#include <stdio.h>

long long arr[1000005][2];

int main()
{
    memset(arr, 0, sizeof(arr));
    arr[0][0] = 0;    arr[0][1] = 0;
    char s[1000005];    scanf("%s", s);
    long long len = strlen(s);
    long long count = 0;
    for(long long i=1; i<len; i++)
    {
        if(s[i]=='v' && s[i-1]=='v')
        {
            arr[i][0] = arr[i-1][0]+1;
            arr[i][1] = arr[i-1][1];
            count += arr[i][1];
        }
        else if(s[i]=='v')
        {
            arr[i][0] = arr[i-1][0];
            arr[i][1] = arr[i-1][1];
        }
        if(s[i]=='o')
        {
            arr[i][1] = arr[i-1][1] + arr[i-1][0];
            arr[i][0] = arr[i-1][0];
        }
    }
    printf("%lld\n", count);
    return 0;
}