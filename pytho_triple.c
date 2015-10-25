/*complexity n*(n-1)/2*/
main()
{
   int n=1000, i, j,k, count=0, match =  0;
   int a[n];
   for (i=0;i<n;i++) a[i] = i+1;
   
   for (i=3;i<=n; i++) {
      j = i-1;
      k = 0;
      do {
        count++;
        if (a[i]*a[i] > (a[j]*a[j] + a[k]*a[k]))
           k++;
        else if  (a[i]*a[i] <  (a[j]*a[j] + a[k]*a[k]))
           j--;
        else {
           match++;
           printf ("(%d, %d, %d) ", a[k], a[j], a[i]);
           k++;
           j--; 
        }

      }while(j>k);
   }
   printf ("Match %d Iternations %d \n", match, count);
}
