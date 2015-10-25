#include <stddef.h>

typedef struct x{
int i;
int arr[1];
}a;

int fun (a b)
{
printf ("Inside fun %d", b.i);
return 0;
}

main()
{
a A, B;
A = B;
A.i = 10;
fun (A);
printf("size of a %d %d", sizeof(A), offsetof(a, arr[0]));
}
