#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;  scanf("%d", &n);
        int arr[200]={0};
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int count = 1;
        if(arr[1]<arr[0])       count++;
        if(arr[2]<arr[0] && arr[2]<arr[1])      count++;
        if(arr[3]<arr[0] && arr[3]<arr[1] && arr[3]<arr[2])     count++;
        if(arr[4]<arr[0] && arr[4]<arr[1] && arr[4]<arr[2] && arr[4]<arr[3])    count++;
        for(int i=5; i<n; i++)
        {
            if(arr[i]<arr[i-1] && arr[i]<arr[i-2] && arr[i]<arr[i-3] && arr[i]<arr[i-4] && arr[i]<arr[i-5])
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}