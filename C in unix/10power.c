/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ***********
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw5, 10power.c
 *Description:finds the power of a number using recursion
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

float power(float x, int y);

int main(void) {

               int x, y;
               float answer;

  printf("\nEnter a number: ");
  x = GetInteger();

  printf("\nEnter the power: ");
  y = GetInteger();

  answer = power(x, y);

  printf("\n%d to the power %d equals: %f\n", x, y, answer);

  return 0;
               }

float power(float x, int y) {

 if (y == 0)
   return 1;
 if ((y % 2) == 0)
   return power(x, y/2) * power(x, y/2);
 else
   return power(x, (y-1)/2) * power(x, (y-1)/2) * x;
                            }



