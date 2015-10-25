main()
{
int *p[10];
int (*p1)[10];
char a[5]="ksk";

printf("%p %p %d %d", a, &a, sizeof(p), sizeof(p1));
}
