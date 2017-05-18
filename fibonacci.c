#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int num, int *arr)
{
    int val;
    if (num <= 1) return num;
    if (arr[num] != 0) { 
        printf("Found memo for %d to be %d\n", num, arr[num]);
        return arr[num];
    }

    val = fib(num-1, arr) + fib(num-2, arr);
    arr[num] = val;
    return val;
}

int main(void)
{
    int num;
    int *arr = 0;
    printf("Enter number : ");
    scanf("%d", &num);

    arr = malloc(sizeof(int) * num);
    memset(arr, 0, sizeof(int)*num);

    printf("Last # in seq for %d is %d \n", num, fib(num, arr));

    
}
