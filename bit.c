#define IPV4_MASKLEN_TO_MASK(mask,masklen)\
{\
   (mask) = (0xFFFFFFFF << (32 - (masklen)));\
   printf("\n %x mask\n", mask);\
}
 
main ()
{
   int masid = 0;
   signed int temp =0xfffffff0;
   unsigned int temp1 = 0xfffffff0;

   
   printf ("%d \r\n", temp);
   printf ("%d \r\n", temp1);
   temp = 0;
   IPV4_MASKLEN_TO_MASK (temp, masid);
   printf ("%x \r\n", temp);
   { (temp) = (0xFFFFFFFF << (32 - (0)));};
   printf ("%x\r\n", temp );
}
