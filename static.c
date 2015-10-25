#include <stdio.h>

int fn ()
{
int i;
static int x ;

printf ("variables : %p %p", &i, &x);
return ++i;
}

int fn1()
{
int i = 0xabcd;
int j=0x1234;
}

main()
{

printf ("\n %d %d", fn (), fn1());
printf ("\n %d %d", fn (), fn1());
printf ("\n %d %d", fn (), fn1());
printf ("\n %d %d", fn (), fn1());
printf ("\n %d %d", fn (), fn1());
}
