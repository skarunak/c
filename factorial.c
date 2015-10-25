int factorial(int fact)
{
  long int result = 0;
  if (fact == 0) return 1;

  result = fact * factorial(fact-1);

  return result;
}

main()
{
int fact = 3;

printf("factorial of %d is \n", factorial(fact));
}
