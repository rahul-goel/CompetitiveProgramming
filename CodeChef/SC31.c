#include <stdio.h>

int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        char weap[10];
        int ans[10] = {0};
        while(n--)
        {
            scanf("%s", weap);
            for(int i=0; i<10; i++)
                ans[i] = (weap[i]-'0')^ans[i];
        }
        int count = 0;
        for(int i=0; i<10; i++)
        {
            if(ans[i])
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}