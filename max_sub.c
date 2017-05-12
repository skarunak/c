#include <stdio.h>

// Kadane algo

int main(void)
{
   int arr[10] = { -2, 1, -3, -4, -1, -2, -1, -5, -4, 0};
   int max_sum = 0;
   int pos_max = 0;
   int i = 0;
   int sum = 0;

   for (i=0; i<10;i++) {
       pos_max = pos_max + arr[i];
       pos_max = (pos_max > 0) ? pos_max : 0;
       max_sum = (pos_max > max_sum) ? pos_max : max_sum;
   }

   printf("Max sum %d \n", max_sum);
}
