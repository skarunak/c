#include <stdio.h>

int main(void)
{
   unsigned int i = 0xd;
   unsigned int mask = 1 << ((sizeof(int)*8)-1);
   unsigned int i_rev = 0;
   unsigned int temp_i = 0xabcd;

   while (i) {
       if (i & 1) i_rev |= mask;
       i >>= 1;
       mask >>= 1;
   }
   printf ("%x %x \n", temp_i, i_rev);
}
