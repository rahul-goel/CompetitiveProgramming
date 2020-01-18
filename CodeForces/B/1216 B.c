//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int comparetor (const void * a, const void * b);
int main()
{
    int n;
    scanf("%d", &n);
    int cans[1001]={0};
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &cans[i]);
    }
    int cans2[1001]={0};
    for(int i=1; i<=n; i++)
        cans2[i] = cans[i];
    qsort(cans2, 1001, sizeof(int), comparetor);
    for(int i=0; i<1001/2; i++)
    {
        int temp = cans2[1000-i];
        cans2[1000-i] = cans2[i];
        cans2[i] = temp;
    }
    for(int i=1001; i>=0; i--)
        cans2[i]=cans2[i-1];
    cans2[0]=0;
    int shots = 0, target = 0;
    for(int i=1; i<=n; i++)
    {
        shots+=(cans2[i]*target +1);
        target++;
    }
    printf("%d\n", shots);
    int note[1001]={0};
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(cans2[i]!=cans[j])
                continue;
            else
            {
                note[i] = j;
                cans[j] = -1;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++)
        printf("%d ", note[i]);
    printf("\n");
    return 0;
}
int comparetor (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}