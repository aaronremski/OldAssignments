/*Author:     Aaron Remski aka. OzHandicraft
<<<<<<< HEAD
 *SSN:        ****
 *Course:
||||||| 83b059a
 *SSN:        060-58-8323 
 *Course:     
=======
 *SSN:        ****
 *Course:     
>>>>>>> 763c4de09d905966dcc83e7e4be3c6652e644c78
 *Assignment: test
 *Description:
 *
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define size 32
#define sentinel 5

int main(void)

{
  int input, counter, index;
  int inputarray[size];        /*variable declaration*/

  index = 0;
  counter = 0;


  while (TRUE)
   {
     printf("\nEnter number (5 to terminate inputs): ");
     input = GetInteger();
       if (input == sentinel) break;
       inputarray[index] = input;
       ++index;
       ++counter;
   } /*end while*/


  for (index = 0; index <= counter; ++index)
    {
       printf("Array[%d]= %d\n", index, inputarray[index]);
    } /*end for*/


    return(0);

}       /*end main*/



