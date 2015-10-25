int f()
{
printf("Stack : \n%p \n%p \n%p \n%p \n%p");
}

main()
{
int i = 0, j=0, k =0 ;
/* printf("Stack : \n%p \n%p \n%p \n%p \n%p"); */
printf ("\n%p %p %p %p\n", &i, &j, &k, main);

f();

}


