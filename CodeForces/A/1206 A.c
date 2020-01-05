#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, killswitch;
    scanf("%d", &n);
    int combined[1000] = {0};
    int *a = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        combined[i] = a[i];
    }
    scanf("%d", &m);
    int *b = malloc(sizeof(int)*m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &b[i]);
        combined[n+i] = b[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            killswitch=0;
            for(int k=0; k<n+m; k++)
            {
                if(a[i]+b[j]==combined[k])
                    killswitch=1;
            }
            if(killswitch==0)
                {
                    printf("%d %d\n", a[i], b[j]);
                    return 0;
                }
        }
    }
    free(a); free(b);
    return 0;
}