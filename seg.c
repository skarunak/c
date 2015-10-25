char * do_copy(char *dst, char *src) {
char *ret = dst;
while (*dst++ = *src++);
return ret;
}
int main()
{
char *a = "First String";
char b[50];

do_copy(b, a);

return 0;
}
