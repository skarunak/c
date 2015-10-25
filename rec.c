#include<stdio.h>
inline int factorial(int a)
{
int multi;
if(a>1)
{
multi = a;
multi *= factorial(a-1);
return multi;
}
else
return 1;

}

int main ()
{
int a,b;
printf("Enter integer:: ");
scanf("%d", &a);
b = factorial(a);
printf(" The factorial of %d is %d",a,b);


}
