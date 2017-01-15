#include <stdarg.h>
#include <stdio.h>

int g_i = 1000;
int g_j = 2000;
int g_k = 3000;

/* this function will take the number of values to average
   followed by all of the numbers to average */
double average ( int num, ... )
{
    va_list arguments;                     
    double sum = 0;
    int x=0;

    /* Initializing arguments to store all values after num */
    va_start ( arguments, num );           
    /* Sum all the inputs; we still rely on the function caller to tell us how
     * many there are */
    for ( x = 0; x < num; x++ )        
    {
        sum += va_arg ( arguments, double ); 
    }
    va_end ( arguments );                  // Cleans up the list

    return sum / num;                      
}

int main()
{
    char *str = "Senthilkumar Karunakaran";
    int i = 100 , j = 200 , k = 300;
    /* this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average) */
    printf( "%f\n", average ( 3, 12.2, 22.3, 4.5 ) );
    printf("%d %d %d \n", i, j, k);
    printf("%d %d %d \n", 400, 500, 600);
    /* here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
    printf( "%f\n", average ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) ); */
}


