//Created by Rahul Goel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);
        int *arr = malloc(sizeof(int)*n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
            int printer = 0;
        for(int i=1; i<n-1; i++) //0 and n-1 will be considered later
        {
            if(arr[i]!=1 && arr[i]!=n)
            {
                if(arr[i+1]==arr[i]+1 && arr[i-1]==arr[i]-1)
                    continue;
                else if(arr[i-1]==arr[i]+1 && arr[i+1]==arr[i]-1)
                    continue;
                else
                {
                    printer = 1; break;
                }
            }
            else if(arr[i]==1)
            {
                if(arr[i+1]==n || arr[i-1]==n)
                    continue;
                else
                {
                    printer = 1; break;
                }
            }
            else // arr[i]==n
            {   //printf("check\n");
                if(arr[i+1]==1 || arr[i-1]==1)
                    continue;
                else
                {//printf("check\n");
                    printer = 1; break;
                }
            }
        }
        if(arr[0]!=1 && arr[0]!=n && arr[n-1]!=1 && arr[n-1]!=n)
        {   
            if((arr[0]+1==arr[1] && arr[0]-1==arr[n-1]) || (arr[0]+1==arr[n-1] && arr[0]-1==arr[1]));
            else    printer = 1;
            if((arr[n-1]+1==arr[n-2] && arr[n-1]-1==arr[0]) || (arr[n-1]+1==arr[0]) && arr[n-1]-1==arr[n-2]);
            else    printer = 1;
        }
        if(arr[0]==1)
        {
            if(arr[1]!=n && arr[n-1]!=n)
                printer = 1;
        }
        if(arr[0]==n)
        {
            if(arr[1]!=1 && arr[n-1]!=1)
                printer = 1;
        }
        if(arr[n-1]==1)
        {
            if(arr[n-2]!=n && arr[0]!=n)
                printer = 1;
        }
        if(arr[n-1]==n)
        {
            if(arr[n-2]!=1 && arr[0]!=1)
                printer = 1;
        }
        
        if(printer==1)
            printf("NO\n");
        else
            printf("YES\n");
        free(arr);
    }
    return 0;
}