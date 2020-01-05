#include <stdio.h>
int shapes(int n);
int arr[100];
int main()
{
    int n; scanf("%d", &n);
    for(int i=0; i<100; i++)
        arr[i]=0;
    arr[2]=2;
    printf("%d\n", shapes(n));
    return 0;
}

int shapes(int n)
{
    if(n&1==1)
        return 0;
    else if(arr[n]!=0)
        return arr[n];
    else
        return (arr[n]=2*shapes(n-2));
}