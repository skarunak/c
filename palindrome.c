#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Find the longest palindrome in a given string */
int main(void)
{
    char str[100]; 
    int arr[100];
    int same_cnt[100];
    int max = 1, i, jth_cnt, j, k, str_len, start=0;

    scanf("%s", str);
    str_len = strlen(str);

    if (str_len == 1) { 
       printf("Str is %s palindrome \n", str);
       return 0;
    }

    for (i=0; i< str_len; i++) { 
        arr[i] = 1 ; same_cnt[i] = 1;
    }

    /* This doesnt work in all the cases :-( ..
     Algo: My own algorithm :-) .. Finding in O(N) time and space.
       Traverse the string and store the lengths of palindromes found in arr,
       and the length of substring of same characters in same_cnt. 
    for (i=1; i<str_len; i++) { 
        j = i - 1;
        jth_cnt = arr[j];
        k = i - jth_cnt - 1; // k position before length of current palindrome
        if ((k >= 0) && (str[k] == str[i])) {
           arr[i] = jth_cnt + 2;
        } 
        k = i - 2;
         Make sure the previous if condition is not travesed (arr[i]==1).
           If previous & current chars match then use the previous char's 
           palindrome length 
        if (arr[i] == 1 && str[i] == str[j]) { 
           if (same_cnt[j] > 1) {
              arr[i] = arr[j]+1; // Use the previous positions length
              same_cnt[i] = same_cnt[j] + 1; // Use previous position repetition count
           } else { 
              arr[i]++;
              same_cnt[i] = same_cnt[i]+1;
           }
        } else if ((arr[i] == 1) && (k>=0) && str[i] == str[k]) {
           arr[i] = 3;
        }

        if (arr[i] > max) {
           start = i - arr[i] + 1;
           max = arr[i];
        }
    }
    */
    printf("Max palindrome lenght %d starting pos %d\n", max, start);
}
