/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        **********
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw5, 9gcd.
 *Description:finds the greatest common divior for two numbers
 *
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int gcd (int n, int d);
int main(void) {

    int n, d, temp;

    printf("---------------------------\n");
    printf("| Greatest Common Divisor |\n");
    printf("---------------------------\n\n");

    printf("Enter first number:  ");
    n = GetInteger();

    printf("Enter second number: ");
    d = GetInteger();

    if (d > n) {
     temp = n;
     n = d;
     d = temp;
               }
    printf("The GCD of %d & %d:  %d\n\n", n, d, gcd(n, d));

    return 0;
               }
int gcd(int n, int d) {

     if ((n % d) == 0)
       return d;
     else
       return gcd((d % n), n);
                      }
