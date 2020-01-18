//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int q;  scanf("%d", &q);
    while(q--)
    {
        int n;  scanf("%d", &n);
        char row1[200005], row2[200005];
        scanf("%s", row1);
        scanf("%s", row2);
        int curr = 0, rownum = 1, change = 0, flag = 0;
        while(curr <= n-2)
        {
            if(rownum==1)
            {
                if(change == 1 && row1[curr]<='2')
                {
                    flag = 1;
                    break;
                }
                else if(change == 1 && row1[curr]>'2')
                {
                    curr++;
                    change = 0;
                }
                else if(row1[curr] <= '2')
                    curr++;
                else
                {
                   rownum = 2;
                   change = 1;
                }
            }
            else
            {
                if(change == 1 && row2[curr]<='2')
                {
                    flag = 1;
                    break;
                }
                else if(change == 1 && row2[curr]>'2')
                {
                    curr++;
                    change = 0;
                }
                else if(row2[curr] <= '2')
                    curr++;
                else
                {
                    rownum = 1;
                    change = 1;
                }
            }
        }
        if(flag==1)
        {
            printf("NO\n");
            continue;
        }
        if(rownum == 2 && row2[curr] <= '2')
            printf("YES\n");
        else if(rownum == 1 && row1[curr] > '2' && row2[curr] > '2')
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}