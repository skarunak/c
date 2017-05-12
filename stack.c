#include <stdio.h>

int f()
{
printf("Stack : \n%lx \n%lx \n%lx \n%lx \n%lx");
}

int main(void)
{
int i = 0x100, j=0x200;
/* printf("Stack : \n%p \n%p \n%p \n%p \n%p"); */
printf ("\n%ld %ld %ld\n", &i, &j, main);

f();
return 0;
}


