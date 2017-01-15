#include <stdio.h>

typedef struct _test_ { 
    float f;
    char c;
    //double a;
    int i;
    int array[0];
} test1;

typedef struct _test_2 { 
    double p;
    char ch;
}test2;
int main(void)
{
   test1 test;
   printf("%d %d %d\n", sizeof(test.f), sizeof(test1), sizeof(test2));
}
