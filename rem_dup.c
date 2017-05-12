#include <stdio.h>

/* Given an sorted array with duplicates, remove the duplicates and
 * return the last index of the array having valid element */
#define NUM 10

int main(void)
{
   int arr[NUM] = {1,1,2,2,3,4,5,6,6,6};
   int i = 0, j = 0, curr;

   curr = arr[0];
   for (i=1, j= 1; i < NUM-1; i++) 
   {
      if (curr != arr[i]) {
         curr = arr[i];
         arr[j++] = arr[i];
      } 
   }

   for (i=0; i< j; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}
