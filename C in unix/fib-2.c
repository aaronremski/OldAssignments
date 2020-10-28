/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ************
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw2, fib-2.c
 *Description:This program displays the first 15 calculations of the
 *            Fibonacci sequence
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()

{
  int f, num1, num2, i, input;     /*variable declaration*/

   printf("\nEnter Fibonacci sequence number: ");
   input = GetInteger();
   printf("\n");

   num1 = 0;
   num2 = 1;
   f = 0;



  for (i = 0; i <= input; i++)
     {
       printf("\nF(%1d) = %2d ", i, f);

       num1 = f;
       f = num2 + num1 ;
       num2 = num1;

     } /*end for*/


   printf("\nWeeeeeeeeeee\n");


}



