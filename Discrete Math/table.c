/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ###
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
   int varcount, linecount, vars; /*variable declaration*/
   int tablearray[32][5];
   int i, row, column;

   printf("\nEnter # of lines in table: ");
   linecount = GetInteger();



   printf("\nEnter # of variables in function: ");
   vars = GetInteger();


   row = 0;


   varcount = linecount;

 for (column = 0; column < vars; column++)
   {

     varcount /= 2;

     while (row < linecount)
       {
         for (i = 0; i < varcount; i++)
		{
		tablearray[row][column] = 1;
		row++;

		} /*end for*/
         for (i = 0; i < varcount; i++)
	        {
	        tablearray[row][column] = 0;
	        row++;

	        }
       } /*end while*/

       row = 0;


   } /*end for*/

   for (row = 0; row < linecount; row++)
    {
    for (column = 0; column < vars; column++)
      {
	 printf("%d ", tablearray [row][column]);
      }
      column = 0;
      printf("\n");
    }

   return 0;

} /*end main*/











