//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
int main()
{
    char str[105];
    scanf("%s", str);
    for(int i=0, n=strlen(str); i<n; i++)
    {   //printf("%d\n", i); //debugging
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='n')
        {
            if(str[i+1]!='a' && str[i+1]!='e' && str[i+1]!='i' && str[i+1]!='o' && str[i+1]!='u')
            {
                printf("NO\n");
                return 0;
            }
            if(str[i+1]=='\0')
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}