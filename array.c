main()
{
int *p[4];
int (*p1)[4];
char a[5]="ksk";
int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12};
printf ("%x %u %u\n", arr[0]+1, *(arr[0]+1), *(*(arr+0)+1));
*p = arr[0];
p1 = &arr[0];
printf("%p %p %d %d\n", a, &a, sizeof(p), sizeof(p1));
}
