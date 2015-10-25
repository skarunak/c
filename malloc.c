main()
{
char *p = (char *)malloc(0);
char *p0 = (char *)malloc(0);
char *p00 = (char *)malloc(0);
char *p1 = (char *)malloc(20);
char *p2 = (char *)malloc(10);

printf("%p %p %p %p %p", p, p0, p00, p1, p2);

printf("\nvalue of p1 %d\n", p1[0]);
p1[0]=97;
memset(p00, "0123456789", 10);
printf("value of p1 %d %c", p1[0], p1[0]);
free(p);
free(p1);
free(p2);

}
