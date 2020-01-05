#include <stdio.h>
#include <math.h>
int main()
{
    int dik, era;
    scanf("%d %d", &dik, &era);
    int i = 1;
    while(1)
    {
        if(i&1==1)
        {
            if(dik>=i) 
                dik-=i;
            else
            {
                printf("Vladik\n");
                return 0;
            }
        }
        else
        {
            if(era>=i)
                era-=i;
            else
            {
                printf("Valera\n");
                return 0;
            }
        }
        i++;
    }
    return 0;
}