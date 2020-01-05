#include <stdio.h>
int rhombus(int n);
int arr[200] = {0};
int main()
{
    arr[1] = 1; arr[2] = 5;
    int n;  scanf("%d", &n);
    printf("%d\n", rhombus(n));
    return 0;
}

int rhombus(int n)
{
    if(arr[n]!=0)
        return arr[n];
    else
        return (arr[n] = 2*rhombus(n-1) - rhombus(n-2) + 4);
}