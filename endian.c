typedef union {
unsigned int i;
char c[4];
}a;

main () 
{
a A;
A.i = 0x0a0b0c0d;
printf ("%x %x %x %x ", A.c[0], A.c[1], A.c[2], A.c[3]);
printf ("%p %p %p %p ", &A.c[0], &A.c[1], &A.c[2], &A.c[3]);
if (A.c[0] == 0x0d) { printf ("little endian"); } else { printf("big endian");}
}
