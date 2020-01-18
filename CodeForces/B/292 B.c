//Created by Rahul Goel
#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100005] = {0};
    int x, y;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &x, &y);
        arr[x]++, arr[y]++;
    }
    //check bus
    int count2=0, count1=0, countstar;
    for(int i=1; i<=n; i++)
    {
        if(arr[i] == 1)
            count1++;
        else if(arr[i] == 2)
            count2++;
        else if(arr[i] == n-1)
            countstar++;
    }
    if(count1 == 2 && count2 == n-2)
        printf("bus topology\n");
    else if(count2 == n)
        printf("ring topology\n");
    else if(countstar && count1 == n-1)
        printf("star topology\n");
    else
        printf("unknown topology\n");
    return 0;
}