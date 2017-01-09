#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __ver {
   int num_octets;
   char ver[64];
} ver_t;

int validate_version(char *ver)
{
}

int my_atoi(char *buf)
{
     int i = 0;
     int itr = strlen(buf)-1;
     int pos = 0;
     while (itr >= 0) {
         i += (buf[itr] - '0') * (!pos ? 1 : (10 * pos));
         pos++;
         itr--;
     }
     return i;
}

int parse_version(char *ver, ver_t *ver_out)
{
   int iter = 0;
   char octets[8];
   int octet_idx = 0;
   int int_iter = 0;
   do
   {
       if (ver[iter] >= 48 && ver[iter] <= 57)
          octets[octet_idx++] = ver[iter];

       if ((ver[iter] < 48 || ver[iter] > 57) || (iter == (strlen(ver)-1))) {
          octets[octet_idx] = '\0';
          octet_idx = 0;
          //ver_int[int_iter++] = atoi(octets);
          ver_out->ver[int_iter++] = my_atoi(octets);
       }
       iter++;
   }while (iter < strlen(ver));
   ver_out->num_octets = int_iter - 1;
   return 0;
}

int compare_versions(ver_t *ver1, ver_t *ver2, ver_t *out_ver)
{
   int ver1_len = ver1->num_octets;
   int ver2_len = ver2->num_octets;
   int i , len;

   out_ver = 0x0;

   len = (ver1_len > ver2_len) ? ver2_len : ver1_len;

   for (i = 0; i <= len; i++) {
      if (ver1->ver[i] > ver2->ver[i]) { 
          out_ver = ver1;
          break;
      } else if (ver1->ver[i] < ver2->ver[i]) { 
          out_ver = ver2;
          break;
      }
   }

   if (out_ver == 0x0) { 
      out_ver = (ver1_len > ver2_len) ? ver1 : ver2;
   }
   if (out_ver == ver1) { 
       printf("Version 1 is latest \n");
   } else {      
       printf("Version 2 is latest \n");
   }
   return 0;
}

int main(int argc, char *argv[])
{
   char ver1[64], ver2[64] ;
   ver_t ver_t1, ver_t2, out_ver;

   printf("Enter version 1: ");
   scanf("%s", ver1);

   printf("Enter version 2: ");
   scanf("%s", ver2);

   // Validate inputs ...

   // Parse and compare
   parse_version(ver1, &ver_t1);
   parse_version(ver2, &ver_t2);
  
   compare_versions(&ver_t1, &ver_t2, &out_ver);
}
