#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
   char *haystack = "missisipi";
   char *needle = "issi";
   char *temp = haystack;
   int idx = -1;

   while (*haystack) {
       if (!memcmp(haystack, needle, strlen(needle))) {
           printf ("%d ", haystack - temp);
           return 0;
       }

       haystack++;
   }


   printf ("Not found ..");
}
