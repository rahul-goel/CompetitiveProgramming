//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n, m; scanf("%d %d", &n, &m);
        int arr[2000] = {0};
        int count[200] = {0};
        int flag = 0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &arr[i]);
            for(int j=1; j<=n; j++)
            {
                if(count[arr[i]]>count[j])
                    flag = 1;
            }
            count[arr[i]]++;
        }
        if(flag==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}