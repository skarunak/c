#include <stdio.h>

void printx(int argc, char (*str)[20])
{
    int i = 0;
    for (i=0; i<argc; i++)  {
        //printf("%s \n", &(str[i*10]));
        printf("%s \n", str[i]);
    }
}

int main(int argc, char *argv[])
{
   char ch[10][20];
   int i = 0;
    for (i=0; i<argc; i++)  {
        printf("%s \n", argv[i]);
    }
   for (i=0; i<10; i++) 
      strncpy(ch[i], "Senthil ", strlen("Senthil "));

   printx(10, ch);
}
