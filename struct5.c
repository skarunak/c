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
}
