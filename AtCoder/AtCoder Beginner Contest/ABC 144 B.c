#include <stdio.h>
int main()
{
    int n;  scanf("%d", &n);
    int flag = -1;
    for(int i=1; i<=9; i++)
    {
        if(n%i==0 && ((n/i)/10)==0)
            flag = 1;
    }
    if(flag==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}