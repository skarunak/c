#include <stdio.h>
char *p1 = "kumar1"; /* Text segment. cannot be edited */
main()
{
char a[20]="senthil"; /* Stack */
char *p = "kumar"; /* Text segment. cannot be edited */
char *m = (char *)malloc(10);
//p[3] = 'x'; /* Seg fault */
a[3] = 'x'; 
printf("%p %p %p %p", p, a, p1, m);


}
