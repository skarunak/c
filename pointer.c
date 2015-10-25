main()
{
int (*p) [5];
printf("sizes %d %d values %d %d", sizeof(p), sizeof(*p), p, *p);
}
