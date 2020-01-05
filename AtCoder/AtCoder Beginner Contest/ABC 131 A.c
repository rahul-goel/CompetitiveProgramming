#include <stdio.h>
int main()
{
    char str[10];
    scanf("%s", str);
    int flag = 1;
    for(int i=1; i<=4; i++)
    {
        if(str[i]==str[i-1])
            flag=0;
    }
    if(flag==1)
        printf("Good\n");
    else
        printf("Bad\n");
    return 0;
}