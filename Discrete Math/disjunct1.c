/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        ****
 *Course:     COT 3100
 *Assignment: disjunct.c
 *Description:This program will accept up to 32 1s & 0s and print out the
 *disjunctive normal form(aka product-of-sums)
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define MAXROW 32
#define MAXCOLUMN 5
#define SENTINEL 2

void getvalues(int *pinputarray[MAXROW], int *plinecount);
int powerchk (int linecount); 
void createtable (int linecount, int vars, int inputarray[MAXROW]);

/*int writefunction (int *inputarray[MAXROW],int *linecount);*/

int main(void)
  {
   
    int variables, linecount;
    int inputarray[MAXROW];  

    getvalues(&inputarray, &linecount);
	
    variables = powerchk(linecount); 

    createtable(linecount, variables, inputarray);

    return 0;

  } /*end main*/

/*--------------------------------------------------------*/
/*--------------------------FUNCTIONS---------------------*/
/*--------------------------------------------------------*/

/* FUNCTION getvalues */

  void getvalues(int *pinputarray[MAXROW], int *plinecount)
    {
      int input, index, counter;        /*variable declaration*/

      index = 0;
      counter = 0;
  
      while (TRUE)
       {
         printf("\nEnter 1 or 0 (2 to terminate inputs): ");
         input = GetInteger();
         if (input == SENTINEL) break;
         *pinputarray[index] = input;
         ++index;
         ++*plinecount;
       } /*end while*/
    
    } /*end function*/  

/*-------------Powerchk----------------------*/
int powerchk (int linecount)
 {
    int vars;

    while (linecount != 1)
     {
       if ((linecount % 2) != 0)
        {
          printf("You enterned an incorrect # of values.\n");
          printf("Be sure your toal inputs equal a power of 2.\n\n");
          printf("Enter new value: ");
          linecount = GetInteger();
	     vars = 0;
        } /*end if*/
       else
        {
          vars++;
          linecount = linecount / 2;

        } /*end else*/
     } /*end while*/

	return(vars);

  } /*end powerchk*/

/*-----------------------Createtable------------------*/
void createtable (int linecount, int vars, int inputarray[MAXROW])
 {
   int varcount; /*variable declaration*/
   int tablearray[MAXROW][MAXCOLUMN];
   int i, row, column;

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

   for (row = 0; row < (linecount - 1); row++)
    {
    for (column = 0; column < vars; column++)
      {
	 printf("%d ", tablearray [row][column]);
      }
       printf("%d", inputarray [row]);
      column = 0;
      printf("\n");
  
    } /*end for*/
} /*end function*/
