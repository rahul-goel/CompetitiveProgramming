#include <stdio.h>
#include <string.h>
int main()
{
    char str[500000];
    scanf("%s", str);
    int length = strlen(str);
    int min = str[0];
    for(int i=0; i<length; i++)
    {
        if(str[i]>min)
            printf("Ann\n");
        else
            printf("Mike\n");
        if(str[i]<min)
            min = str[i];
    }

    return 0;
}