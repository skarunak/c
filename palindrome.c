#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Find the longest palindrome in a given string */
int main(void)
{
    char str[100]; 
    int arr[100];
    int max = 1, i, jth_cnt, j, str_len, start;

    scanf("%s", str);
    str_len = strlen(str);

    for (i=0; i< str_len; i++) arr[i] = 1;

    for (i=1; i<str_len; i++) { 
        j = i - 1;
        jth_cnt = arr[j];
        if ((i - jth_cnt -1 >= 0) && (str[i - jth_cnt - 1] == str[i])) {
           arr[i] = jth_cnt + 2;
        } else if (str[i] == str[j]) { 
           arr[i]++;
        } 
        if (arr[i] > max) {
           start = i - arr[i] + 1;
           max = arr[i];
        }
    }
    printf("Max palindrome lenght %d starting pos %d\n", max, start);
}
