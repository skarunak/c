#include <stdio.h>

typedef struct _test_ { 
    float f;
    double a;
    char c;
    int i;
    int array[0][0];
} test1;

typedef struct _test_2 { 
    double p;
    char ch;
}test2;
int main(void)
{
   test1 test;
   printf("%ld %ld %ld\n", sizeof(test.f), sizeof(test1), sizeof(test2));
}
