//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
int main()
{
    int len;  scanf("%d", &len);
    char str[100005];
    scanf("%s", str);
    int first8 = -1;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='8')
        {
            first8=i;
            break;
        }
    }
    int count8=0;
    for(int i=0; i<len-10; i++)
    {
        if(str[i]=='8')
            count8++;
    }
    if(count8>=(len-9)/2)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}