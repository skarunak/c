#include <stdio.h>

int main(void)
{
    short i = -20000;
    int j = i;
    float f = 7.0;
    short s_f = *(short *)&f;
    short s_f1 = f;
    // Understand how float is represented in memory, after that only the above assignment will make sense 
    printf("%d %d %d %d \n", i , j, s_f, s_f1);
}
