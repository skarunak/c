#include <stdio.h>

int q_partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int partition_idx = start;
    int i, temp;

    if (start < end) {
    // Leave out pivot idx, reassemble all others
    for (i=start; i<end-1;i++) {
        if (arr[i] <= pivot) {
           temp = arr[i];
           arr[i] = arr[partition_idx];
           arr[partition_idx++] = temp;
	}
    }
    // Swap the pivot in place of the partition completes..
    if (arr[partition_idx] > pivot) { 
	temp = arr[partition_idx];
        arr[partition_idx] = arr[end];
        arr[end] = temp;
    }}
    return partition_idx;
}

void quicksort(int *arr, int start, int end)
{
   if (start < end) {
     int pivot_idx = q_partition(arr, start, end);
     quicksort(arr, start, pivot_idx-1);
     quicksort(arr, pivot_idx+1, end);
   }
}

// Find kth smallest element
int quickselect(int *arr, int start, int end, int k)
{
    if (start < end) { 
     int pivot_idx = q_partition(arr, start, end);
     if (k == pivot_idx) { 
         return arr[k];
     } else if (k > pivot_idx) {
         return quickselect(arr, pivot_idx+1, end, k);
     } else {
         return quickselect(arr, start, pivot_idx-1, k);
     }
    } else if (start == end) {
     return arr[start]; 
    }
    return -1;
}

int merge_sort(int *arr, int low, int high)
{
}

int main(void)
{
   int arr[8] = { 7,2,6,3,5,6,8,4};
   int len = (sizeof(arr)/sizeof(int)) - 1;
   int i;
   int k = 0;

   printf(" Quickselect %dth pos %d \n", k, quickselect(arr, 0, len, k));

   quicksort(arr, 0, len);

   printf("\nQ-sort: ");
   for (i=0; i<=len;i++) {
	printf("%d ", arr[i]);
   }

}
