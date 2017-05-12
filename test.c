#include <stdio.h>

int foo(int a, int b) {
	int c = 0;
	c = a + b;
	//c = abc(c);
	return (c);
}

int abc(int x) {
	int d = 0;
	d = x *2;
	return (d);
}


int
main()
{
	int a, b,c;
	a = 10;
	b = 20;
	foo(a, b);
	a++;
	printf("%d \n", a);
	return (0);
}
