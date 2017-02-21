#include <stdio.h>
#include <string.h>

int main(void)
{
   char s[100];
   char p[10];
   int map[255], count, begin, i, p_len, s_len;

   memset(map, 0, sizeof(map));

   printf("Enter first string : ");
   scanf("%s", s);
   printf("Enter second string : ");
   scanf("%s", p);

   printf("Inputted s:%s p:%s \n", s, p);

   p_len = strlen(p);
   s_len = strlen(s);
   for (i=0; i<p_len; i++) 
      map[p[i]]++;

   count = p_len;
   begin = 0;
   for (i=0; i<s_len; i++) {
       if (map[s[i]]-- >= 1) count--;

       if (count == 0) printf ("%d ", begin);

       if ( ((i - begin) == p_len-1) && (map[s[begin++]]++ >= 0) ) count++;
   }
   
}
