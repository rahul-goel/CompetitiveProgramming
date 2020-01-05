#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, arr[400005];
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int mid = n/2;
        if(arr[mid-1]==arr[mid])
        {
            while(arr[mid-1]==arr[mid])
                mid--;
        }

        int gold=0, silver=0, bronze=0, ptr = 0;
        while(ptr<mid)
        {
            int count = 1;
            while(arr[ptr]==arr[ptr+1])
                ptr++, count++;

            //printf("ptr count %d %d\n", ptr, count);

            if(!gold)
                gold += count;
            else if(silver<=gold)
                silver += count;
            else
                bronze += count;
            ptr++;
        }

        if(gold >= bronze || gold >= silver)
            printf("0 0 0\n");
        else
            printf("%d %d %d\n", gold, silver, bronze);
    }
    return 0;
}