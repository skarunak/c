#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 5, y = 6, z=7, i, j,k;
    int *arr = malloc(sizeof(int)*x*y*z);
    int ***arr3d = 0;

    for (i =0; i < (x*y*z); i++) {
       arr[i] = i;
    }
    arr3d = malloc(sizeof(int **) * z);

    for (i=0; i<z; i++) {
        arr3d[i] = malloc(sizeof(int *) * y);
	for (j=0; j<y; j++) {
            arr3d[i][j] = arr + (i * y * x)+ (j*x);
	}
    }

    for (i=0; i< z; i++)
 	for(j=0;j<y;j++)
		for (k=0; k<x;k++)
			printf(" %d ", arr3d[i][j][k]);

    return 0;
}
