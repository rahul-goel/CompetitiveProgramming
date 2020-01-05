#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[100005], b[100005];
    scanf("%s", a);
    scanf("%s", b);
    int l = strlen(a);
    int cnta4=0, cnta7=0, count=0;
    for(int i=0; i<l; i++)
    {
        if(b[i]!=a[i] && a[i]=='4')
        {
            if(cnta7)
            {    
                cnta7--; count++;
            }
            else cnta4++;
        }
        else if(b[i]!=a[i] && a[i]=='7')
        {
            if(cnta4)
            {
                cnta4--; count++;
            }
            else cnta7++;
        }
    }
    count+=cnta4+cnta7;
    printf("%d\n", count);
    return 0;
}