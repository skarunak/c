#include <stdio.h>

int main(void)
{
   char a[10] = "senthil";
   char b[10] = "entslihk";
   char ch;
   unsigned int xor = 0;
   int i = 0;

   // Since XOR is cumulative. 2^3^2==3. So XOR the whole string and XOR it again to nullify then the remaining char is the extra one
   while (ch = a[i++]) { 
	xor ^= ch;
   }

   i = 0;
   while (ch = b[i++])
	xor ^= ch;
 
   printf("%c \n", xor);   

}
