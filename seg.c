int g = 1;

char * do_copy(char *dst, char *src) {
char *ret = dst;
while (*dst++ = *src++);
return ret;
}
int main()
{
char *a = "First";
char b[50];
int i = 0;
int j = 0;
int k;

do_copy(b, a);

return 0;
}
