#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int *i = malloc(10);

   free(i);
   free(i);
   return 0;
}
