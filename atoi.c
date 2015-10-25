int myatoi(const char *string)
{
int i;
i=0;
while(*string)
{
i=(i<<3) + (i<<1) + (*string - '0');
string++;
// Dont increment i!
}
return(i);
}

main()
{

   printf("Integer equivalent of %d\n",  myatoi("1998"));
}


