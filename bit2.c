main()
{
int i = 0x00000003;
unsigned int j = 0x80000000;
unsigned char c = 0x80;
printf("ch %d ", c<<1);
printf("i %x i %x j %x j %x", i << 1, i >>1, j <<1, j>>1);
}
