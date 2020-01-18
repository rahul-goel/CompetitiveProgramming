//Created by Rahul Goel
#include <string.h>
#include <stdio.h>
typedef long long ll;
int main()
{
    char str[10005];
    scanf("%s", str);
    int m;  scanf("%d", &m);
    int len = strlen(str);
    while(m--)
    {
        int l, r, k;    scanf("%d %d %d", &l, &r, &k);
        l--; r--;
        k = k%(r-l+1);
        char temp[r-l+1];
        for(int i=0; i<r-l+1; i++)
            temp[i] = str[l+i];
        for(int i=0; i<r-l+1; i++)
            str[l+(i+k)%(r-l+1)] = temp[i];
    }
    printf("%s\n", str);
    return 0;
}