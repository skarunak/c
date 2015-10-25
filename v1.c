int f1(char *str){

char str1[4];

strcpy(str1, str);
printf ("Stack \n: \n%p \n%p \n%p \n%p \n");
return 0;
}

int f2(){
printf("\n Executed the second function\n");
return 0;
}

main(int argc, char **argv)
{

printf("\n address of f2 %x \n", f2);

f1(argv[1]);

return 0;
}

