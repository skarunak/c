main()
{
signed char i = -1; i = i >> 1; 
unsigned char j = 255; j = j >> 1; 

printf ("%d %d", i, j);

i = i >> 4;
j = j >> 2;

printf ("%d %d", i, j);
}
