#include <stdio.h>
int main()
{   
    int n; scanf("%d", &n);
    int cntpos=0, cntneg=0;
    while(n--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x<0)
            cntneg++;
        else
            cntpos++;
    }
    if(cntpos>1 && cntneg>1)
        printf("NO\n");
    else if(cntpos>1 && cntneg<=1)
        printf("YES\n");
    else if(cntneg>1 && cntpos<=1)
        printf("YES\n");
    else if(cntneg==1 && cntpos==1)
        printf("YES\n");
    return 0;
}