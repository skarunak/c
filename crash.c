main()
{
int *p = malloc(100);
int *p1 = malloc(0x200);

free (p+10);

}
