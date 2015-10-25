typedef struct n { int i ; int j; }a;
main()
{
a *p=0;
a *q = p + 1;
printf ("%p %p", p, q);
printf("%d", (char *)q-(char *)p);
}
