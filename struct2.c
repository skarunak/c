/*#pragma pack(1) */
struct example1 {
char c1;
short s1;
char c2;
long l1;
char c3;
}a;

struct example2 {
long l1;
short s1;
char c1;
char c2;
char c3;
char pad[3];
}b;

struct example3 {
int i;
short s;
char c;
}c;

main ()
{
printf("size of %d %d %d", sizeof(a), sizeof(b), sizeof(c));
}
