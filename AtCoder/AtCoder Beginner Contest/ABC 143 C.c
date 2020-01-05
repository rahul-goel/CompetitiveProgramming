#include <stdio.h>
#include <string.h>
int main()
{
    int n;  scanf("%d", &n);
    char str[100005];
    scanf("%s", str);
    int count = 0;
    for(int i=0; i<n; i++)
    {
        while(str[i]==str[i+1])
            i++;
        count++;
    }
    printf("%d\n", count);
    return 0;
}