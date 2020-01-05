#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
/*int comparetor (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}*/
//MERGESORT FROM GEEKSFORGEEKS TO AVOID TLE IN QSORT
int main()
{
    int n;  scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    int *diff = malloc(sizeof(int)*(n-1));
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    //qsort(arr, n, sizeof(int), comparetor);
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n-1; i++)
        diff[i] = (int)fabs(arr[i]-arr[i+1]);
    //qsort(diff, n-1, sizeof(int), comparetor);
    mergeSort(diff, 0, n-2);
    int count = 1, i=0;
    while(diff[i]==diff[i+1])
    {
        i++;
        count++;
    }
    printf("%d %d\n", diff[0], count);
    free(arr);
    free(diff);
    return 0;
}
 
//MERGESORT FROM GEEKS FOR GEEKS TO AVOID TLE DUE TO QSORT.
 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}