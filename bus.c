#include <stdlib.h> 
#include <stdio.h> 

int main(void) 
{ 
  char *c; 
  long int *i; 
  c = (char *) malloc(sizeof(char)); 
  c++; 
  i = (long int *)c; 
  printf("%ld", *i); 
  return 0; 
} 
