#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *num1 = "1234567";
    char *num2 = "1111111";
    char *temp;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int c = 0;
    if (len1 < len2) {
        temp = num2;
        num2 = num1;
        num1 = temp;

	len1 ^= len2;
        len2 ^= len1;
        len1 ^= len2;
    }

    char *res = malloc(len1+2); // 1 for /0 & another for carry
    res[0] = '0';
    res[len1+1] = '\0';
    memcpy(res+1, num1, len1);
    len1++;
    while(--len2 >= 0 && --len1 >= 0) {
        c = c + (res[len1] - '0') + (num2[len2] - '0');
        res[len1] = c % 10 + '0';
        c = c / 9;
    } 

    printf("%s \n", res);
}
