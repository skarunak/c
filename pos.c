
#define offsetof(TYPE, MEMBER) ((unsigned int) &((TYPE *)0)->MEMBER)
typedef struct
{
int i;
char c[30];
int j;
int k;
} st;

main ()
{
printf ("\n i %d c %d j %d", offsetof(st, i), offsetof(st,c), offsetof(st,j));
}
