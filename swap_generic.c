#include <stdio.h>
#include <string.h>

void swap(void *p, void *s, int size)
{
   char temp[size];

   memcpy(temp, p, size);
   memcpy(p, s, size);
   memcpy(s, temp, size);

}

int main(void)
{
   int i = 10, j = 20;
   double d = 0x100, e = 0x200;
   char *a = "arthi";
   char *s = "senthil";

   swap(&i, &j, sizeof(i));
   swap(&d, &e, sizeof(d));
   swap(&a, &s, sizeof(char *));

   printf("%d %d %s %s %ld %ld \n", i, j, a, s, d ,e);
   return 0;
}
