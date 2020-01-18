//Created by Rahul Goel
//should have used long long int but still got accepted.
#include <stdio.h>
int main()
{
    int n;  scanf("%d", &n);
    int arr[200000] = {0};
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int time=arr[0]+1, height=arr[0];
//for every loop we calculate time till eating the nut. coming down that tree gets added in next loop.
    for(int i=1; i<n; i++)
    {
        if(arr[i]>=arr[i-1])
            time+=arr[i]-arr[i-1]+2;//climbing up + jump + eating        
        else
            time+=arr[i-1]-arr[i]+2;//climbing down + jump + eating
    }
    printf("%d\n", time);
    return 0;
}