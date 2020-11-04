/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ***
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment:
 *Description:
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(void)

{
	int linecount, variables;


   printf("\nEnter linecount: ")
   linecount = GetInteger();
   printf("\n");
   printf("\nEnter # of variables, must correspond\n ")
   printf("\nwith # of lines: ")
   variables = GetInteger();


	row = 0;
	varcount = 2;

   for (column = 0; column <= variables; column++)
	{
          while (row <= linecount)
	  for (row = , row <= (linecount / varcount); row++)
	       {
		  tablearray[column][row] = 1;
	       }
	  for (row = (linecount / 2); row <= linecount; row++)
	       {
		  tablearray[column][row] = 0;
		}
  	   varcount = varcount * varcount
	   row = 0;

	return(0);
}



