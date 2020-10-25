/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *****************
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw3, prodsum.c
 *Description:Returns the product and sum of the
 *            5 numbers given
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define MAXNUM 5

void prodsum (int inputarray[MAXNUM], int *prod, int *sum);

int main(void)
{
  int inputarray[MAXNUM], index;    /*variable declaration*/
  int mainsum, mainprod;

  printf("Please enter 5 integers each followed by an ENTER\n");

  for (index = 0; index < MAXNUM; index++)
    {
    printf("    #%d: ", (index + 1));
    inputarray[index] = GetInteger();
    }

  prodsum(inputarray, &mainprod, &mainsum);

  printf("PRODUCT   = %d\n", mainprod);
  printf("SUMMATION = %d", mainsum);

    return 0;
}

/*----------------------------------------------------------*/
/*----------------------FUNCTIONS---------------------------*/
/*----------------------------------------------------------*/
/*FUNCTION PRODSUM*/

void prodsum(int inputarray[MAXNUM], int *prod, int *sum)
  {
    int index;

    *sum = 0;
    *prod = 1;

     for (index = 0; index < MAXNUM; index++)
      {
        *sum += inputarray[index];
        *prod *= inputarray[index];
      }
  }
