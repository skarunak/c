#include <stdio.h>

typedef struct {
    short  ch1;
    int ch2;
} ch;

typedef struct {
    int i;
    double j;
    short s;
} i;
int main(void)
{
    printf("%d %d\n", sizeof(ch), sizeof(i));
    i i1 = { i: 5, j:10.05, s:2};
    i i2 = { 6, 16.05, 7};
    i i3 = { s:6, i:16, j:7.5};
}
