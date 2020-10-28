/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        **************
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment: hw3, gates.c
 *Description:toggles 100 cells/gates, certain cells remain
 *            open
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void close (int array[], int n);
void toggleall (int array[], int step);
bool isopen (int array[], int i);
int main (void)
  {

  int parray[100];
  int i;
  int step;

    for (i = 1; i <= 100; i++)
      close (parray,i);

    for (step = 1; step <= 100; step++)
      toggleall (parray,step);

    printf ("The following cell doors will be open: \n");

    for (i = 1; i <= 100; i++)
     {
       if (!isopen(parray,i))
         printf ("%d, ", i);
     }
   return (0);

  }




/*---------------------------------------------------*/
/*----------------FUNCTIONS/PROCEDURES---------------*/
/*---------------------------------------------------*/

void close (int array[], int n)
  {
    array[n-1] = 1;
  }

/*---------------------------------------------------*/
void toggleall (int array[], int step)
  {

  int i;

  for (i = step; i <= 100; i += step)
    array[i-1] += 1;

  }
/*---------------------------------------------------*/
bool isopen (int array[], int i)
  {
    if ((array[i-1] % 2) == 0)
    return (FALSE);

    return (TRUE);
  }
/*---------------------------------------------------*/
