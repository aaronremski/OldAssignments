/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *******
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw5, 11sqrt.c
 *Description:finds the sqaure root of a number using recursion
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

float sqt (int x);
float newton (float a, int x);

int main(void) {

     int x;

     printf("--------------------------\n");
     printf("|      Square Root       |\n");
     printf("--------------------------\n\n");

     printf("Find square root for what number: ");
     x = GetInteger();

     printf("\nThe square root of %d is: %f\n", x, sqt(x));

     return 0;

}

float sqt (int x) {

        float a;

   a = x / 2;

   if (abs(a * a - x) <= 2.71828182)
     return a;
   else
     return newton(a, x);
                  }

float newton (float a, int x) {

        a = (a + x / a) / 2;

	if (abs(a * a - x) <= 2.71828182)
	  return a;
	else
	  return newton(a, x);
                              }



