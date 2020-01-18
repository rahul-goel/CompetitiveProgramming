//Created by Rahul Goel
#include <stdio.h>
#include <string.h>
int min(int a, int b)
{
    if(a<=b)
        return a;
    else 
        return b;
}
int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    int t;  scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        char room[1005];    scanf("%s", room);
        int store1=-1;
        for(int i=0, l=strlen(room); i<l; i++)
        {
            if(room[i]=='1')
            {
                store1 = max(l-i, store1);
                break;
            }
        }
        int store2=-1;
        for(int i=strlen(room)-1; i>=0; i--)
        {
            if(room[i]=='1')
            {
                store2 = max(store2,i+1);
                break;
            }
        }
        int store = max(store1, store2);
        if(store==-1)
            printf("%d\n", n);
        else
            printf("%d\n", 2*store);
    }
    return 0;
}