/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ****
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw2, fib-2.c
 *Description:This program displays the first 15 calculations of the
 *            Fibonacci sequence
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(void)

{

   int inputcount, variables;     /*variable declaration*/

   variables = 0;

   printf("\nSimilute counter for array elements, value: ");
   inputcount = GetInteger();
   printf("\n");

   while (inputcount != 1)
     {
       if ((inputcount % 2) != 0)
        {
          printf("You enterned an incorrect # of values.\n");
          printf("Be sure your toal inputs equal a power of 2.\n\n");
	  printf("Enter new value: ");
          inputcount = GetInteger();
	  variables = 0;
        }

       else
        {
          variables++;
          inputcount = inputcount / 2;
        }


     } /*end while*/


     printf("There will be %d variables", variables);

        return(0);

}



