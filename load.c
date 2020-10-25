/*Author:     Aaron Remski aka. OzHandicraft
 *SSN:        *****
 *Course:     cis3020 Intro to CIS Fall 1999
 *Assignment:
 *Description:
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define fname "words.txt"
#define MAXWORDS 25  /*max words defined as MAXWORDS - 1 because of
                      *array index*/

int main(void)

{
  FILE *inputfile;     /*variable declaration*/
  string word;
  string wordarray[MAXWORDS];
  int index;

  if((inputfile = fopen(fname, "r")) == NULL)
	printf("WORD FILE NOT FOUND %s\n", fname);

  index = 0;

  while((word = ReadLine(inputfile)) != NULL)
   {
     wordarray[index] = word;
     index++;

   }

   fclose(inputfile);

    return 0;
}


/*----------------------------------------------------------*/
/*----------------------FUNCTIONS---------------------------*/
/*----------------------------------------------------------*/




