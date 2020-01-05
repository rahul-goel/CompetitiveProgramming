#include <stdio.h>
int sumofdig(int n);
int main()
{
    int a;  scanf("%d", &a);
    while(sumofdig(a)%4!=0)
        a++;
    printf("%d\n", a);
    return 0;
}

int sumofdig(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}