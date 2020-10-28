/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *******************
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw2, PrimFact-4.c
 *Description:This program finds the prime factors of the given number
 */
#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

bool IsPrime(int n);
void PrimeFactor(int n);
int NextPrime(int x);

int main(void)
  {
        int num;

        printf("\nPRIME FACTORIZATION\n\n");
        printf("Enter number to find prime factors: ");
	num = GetInteger();

        if(IsPrime(num) == TRUE)
	  {
	  printf("The number you entered is a prime number\n");
          }
        else
          {
          PrimeFactor(num);
          }

        return(0);

  } /*end Main*/

/*------------------------FUNCTIONS---------------------*/
/*NEXTPRIME*/
int NextPrime(int x)
  {
     x++;
	while (!(IsPrime(x)))
       {
         x++;
       }

        return(x);

  } /*end NextPrime*/


/*ISPRIME*/
bool IsPrime(int n)

 {

    int i, limit;

    if (n <= 1) return (FALSE);
    if (n == 2) return (TRUE);
    if (n % 2 == 0) return (FALSE);
    limit = (int)sqrt(n) + 1;
    for (i = 3; i <= limit; i += 2)
      {
        if (n % i == 0) return (FALSE);
      }

    return (TRUE);

 } /*end IsPrime*/

/*--------------------FindPrime--------------------*/
void PrimeFactor(int n)

  {

        int prime;

        prime = 2;

        while (n != 1)
         {
          while ((n % prime) == 0)
             {  n = n / prime;
                printf("%d", prime);
                 if (n != 1)
 			printf (" * ");
          } /*end 2nd while*/
	  if (n != 1)
           prime = NextPrime(prime);

         } /*end 1st while */
       printf ("\n");
       return;
  } /*end PrimeFactor*/






