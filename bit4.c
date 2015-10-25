main()
{
int i = 230, pos = 10, temp;
temp = 0x1 << (pos-1);
if (i & temp) { printf ("Bit %d is set", pos); } 
else { printf ("Bit %d is unset", pos); }
}
