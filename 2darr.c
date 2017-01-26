#include <stdio.h>
#include <string.h>

void printx(int argc, char (*str)[20])
//void printx(int argc, char **str)
{
    int i = 0;
    for (i=0; i<argc; i++)  {
        //printf("%s \n", &(*(str+(i*20))));
        printf("%s \n", str[i]);
    }
}

int main(int argc, char *argv[])
{
   char ch[10][20];
   int arr[10][20];
   int *ptr = arr[0];
   int (*ptr1)[20] = &arr[0];
   int i = 0;
    for (i=0; i<argc; i++)  {
        printf("%s \n", argv[i]);
    }
   for (i=0; i<10; i++) 
      strncpy(ch[i], "Senthil ", strlen("Senthil ")+2);

   //printx(10, (char **)ch);
   printx(10, ch);
}
