/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        060-58-8323 
 *Course:     COT 3100
 *Assignment: disjunct.c
 *Description:This program will accept up to 32 1s & 0s and print out the
 *disjunctive normal form(aka product-of-sums)
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define MAXROW 40
#define MAXCOLUMN 10



int powerchk (int linecount); 
void createtable (int linecount, int vars, int inputarray[MAXROW], int *tablearray[MAXROW][MAXCOLUMN]);

void display(int linecount, int vars, int inputarray[MAXROW],
             int tablearray[MAXROW][MAXCOLUMN]);

/*int writefunction (int inputarray[MAXROW],int linecount);*/

int main(void)
  {
   
    int variables, linecount;
    int input, index, counter;        /*variable declaration*/
    int inputarray[MAXROW], tablearray[MAXROW][MAXCOLUMN];
    
    index = 0;
    counter = 0;
    variables = 0;
    linecount = 0;
    input = 0;

      while ((input == 1) || (input == 0))
       {
         printf("\nEnter 1 or 0 (terminate inputs with any other integer: ");
	 input = GetInteger();
           if ((input == 1) || (input == 0))
	   {
         inputarray[index] = input;
         index++;
         linecount++;
           }

       } /*end while*/
       
       printf("\nlinecount equals %d  after input", linecount);
       variables = powerchk(linecount); 
       printf("\nvariables equal %d after powerchk\n", variables);
       
        if (variables != 0)
	  {
            createtable(linecount, variables, inputarray, &tablearray);
	    display(linecount, variables, inputarray, &tablearray);
	  } 
  
    return (0);

  } /*end main*/

/*--------------------------------------------------------*/
/*--------------------------FUNCTIONS---------------------*/
/*--------------------------------------------------------*/

/*-------------Powerchk----------------------*/
int powerchk (int linecount)
 {
    int vars;

    vars = 0;

    while (linecount != 1)
     {
       if ((linecount % 2) != 0)
        {
          printf("You enterned an incorrect # of values.\n");
          printf("Be sure your total inputs equal a power of 2.\n\n");
          vars = 0;
          linecount = 1;
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
void createtable (int linecount, int vars, int inputarray[MAXROW], int *tablearray[MAXROW][MAXCOLUMN])
 
 {
   int varcount; /*variable declaration*/
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
		*tablearray[row][column] = 1;        
		row++;
	      
		} /*end for*/
         for (i = 0; i < varcount; i++)
	        {
	        *tablearray[row][column] = 0;	
	        row++;
	        }  

       } /*end while*/

       row = 0;

   } /*end for*/
       
       

 } /*end procedure*/

 /*--------------------Display--------------------*/

void display (int linecount, int vars, int inputarray[], int tablearray[][])
  { int column, row;
   
    for (column = 0; column < vars; column++)
     { printf("X%d ", (column + 1));
     }
   
   printf("F(variables)\n");
       
    for (row = 0; row < linecount; row++)
    {

     for (column = 0; column < vars; column++)
       {
        printf("  %d ", tablearray[row][column]);
       }
      printf("%d", inputarray [row]);
      column = 0;
      printf("\n");

    } /*end for*/

} /*end function*/


