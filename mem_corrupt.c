main()
{
char *p1 = malloc(100);
char *p2 = malloc(200);
char *p3 = malloc(300);
char *p4 = malloc(400);

p1 = p1-4;
p1[0] = 0xaa;
printf("%p", p1);
free(p1);
}
