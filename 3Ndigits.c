/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        
 *Course:     cis3020 Intro to CIS Fall 1999         
 *Assignment: hw3, Ndigits-3.c
 *Description:Counts the number of digits in given number
 *           
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int count(int x); /* Function template count */

int main(void)

{
  
   int number, sum;     /*variable declaration*/
   
   printf("\nEnter Integer: ");
   number = GetInteger();
   
   sum = count(number);

   printf("Number of Digits: %d", sum);
   printf("\n");

   return(0);
}

/*----------------------------------------------------*/

/*Function - count
 *This function returns the mod(remainder) or x by 10
 *each remainder is a digit of the number
 */

int count(int x)
{ 
  int cnt;  /*function variable declaration*/

  for (cnt = 0; x > 0; cnt++)
    {  
       x = x / 10;
    }   /*end for*/

    return (cnt);

}       /*end function*/


