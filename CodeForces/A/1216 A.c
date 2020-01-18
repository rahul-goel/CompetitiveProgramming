//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    int count = 0;
    for(int i=0; i<n; i+=2)
    {
        if(str[i]=='a' && str[i+1]=='a')
        {    
            count++;
            str[i+1]='b';
        }
        else if(str[i]=='b' & str[i+1]=='b')
        {    
            count++;
            str[i+1]='a';
        }
    }
    printf("%d\n", count);
    printf("%s\n", str);
    return 0;
}