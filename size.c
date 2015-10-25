#define my_sizeof(type) ((&type+1)-(&type))
int main()
{
    double x;
    int i, j;
    int *p1 = &i, *p2=&j;
    printf("%d %d", my_sizeof(x), p1-p2 );
    getchar();
    return 0;
}
