//Created by Rahul Goel
#include <stdio.h>

int main()
{
    int seq[130]={0}, occur[70] = {0};
    int i=3, j;
    occur[0]=2;
    while(i<=128)
    {
        //printf("i = %d\n", i);
        if(occur[seq[i-1]]>=2)
        {
            j=i-2;
            while(seq[i-1]!=seq[j])
                j--;
            seq[i] = i-1-j;
            occur[i-1-j]++;
        }
        else
            seq[i] = 0;
        //printf("seq %d  = %d\n", i, seq[i]);
        i++;
        
    }
    // for(int k=1; k<=128; k++)
    //     printf("%d\n", seq[k]);
    int ans[128]={0};
    for(int k=1; k<=128; k++)
    {
        int ptr = k;
        while(ptr>=1)
        {
            if(seq[ptr]==seq[k])
                ans[k]++;
            ptr--;
        }
    }
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}